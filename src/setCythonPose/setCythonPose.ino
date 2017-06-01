

#include <ros.h>
#include <std_msgs/Int8.h>

ros::NodeHandle  nh;
std_msgs::Int8 cython_state;
ros::Publisher cython("cython", &cython_state);
/*
// Minimo e Maximo do Servo
float min_array2[] = {2330, 2320, 2350, 800, 2370, 2300, 2370};
float max_array2[] = {720, 920, 730, 2100, 610, 600, 580};
float min_degree[] = {-90,-86, -90, -83, -90, -90,-90};
float max_degree[] = {90, 65, 90, 62, 90, 90, 90};*/

int cython_is_buzy = 0;

void pick(){
  
  cython_state.data = 1;
  cython.publish(&cython_state);
  nh.spinOnce();
  
  Serial2.println("#7 P800 #6 P1500 #5 P2300 #4 P1500 #3 P1900 #2 P1500 #1 P1780 #0 P1500 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P800 #6 P1500 #5 P2300 #4 P1500 #3 P2000 #2 P1500 #1 P1820 #0 P1500 T500 <cd> "); // Posicao Inicial 
  delay(500);
  Serial2.println("#7 P800 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P1500 T500 <cd> "); // Posicao final 
  delay(1500);
  nh.spinOnce();
  Serial2.println("#7 P1300 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1300 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
  
  cython_state.data = 0;
  cython.publish(&cython_state);
  nh.spinOnce();
}

void drop_left(){
  cython_state.data = 1;
  cython.publish(&cython_state);
  nh.spinOnce();
  Serial2.println("#7 P1300 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2100 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P1300 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P2100 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  nh.spinOnce();
  Serial2.println("#7 P800 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P2100 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P1300 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
  cython_state.data = 0;
  cython.publish(&cython_state);
  nh.spinOnce();  
}

void drop_right(){
  
  cython_state.data = 1;
  cython.publish(&cython_state);
  Serial2.println("#7 P1300 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P900 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P1300 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P900 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P800 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P900 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  nh.spinOnce();
  Serial2.println("#7 P1300 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);  
  cython_state.data = 0;
  cython.publish(&cython_state);
  nh.spinOnce();
}

void initial_position(){
  cython_state.data = 1;
  cython.publish(&cython_state);
  Serial2.println("#7 P1700 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1500 <cd> "); // Posicao final 
  delay(1500);
  nh.spinOnce();
  cython_state.data = 0;
  cython.publish(&cython_state);
  nh.spinOnce();
}



void messageCb( const std_msgs::Int8& pose){
  
  pick();
  if (pose.data == 1){
    drop_right();
    nh.spinOnce();
    cython.publish(&cython_state); 
  }

  if (pose.data == 2){
    drop_left();
    nh.spinOnce();
    cython.publish(&cython_state); 
  }
  initial_position();
  nh.spinOnce();
}

ros::Subscriber<std_msgs::Int8> sub("pose", &messageCb );


void garra(){
  
    
   cython.publish(&cython_state); 
   nh.spinOnce();   
}

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.getHardware()->setBaud(57600);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(cython);
  Serial2.begin(9600);
  initial_position();
  
}

void loop()
{  
  cython_state.data = 1;
  nh.spinOnce();
  delay(10);
   
}

