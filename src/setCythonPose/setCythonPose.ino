

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

const int red_buttonPin = 3;     // the number of the pushbutton pin
const int red_ledPin =  5;      // the number of the LED pin

const int green_buttonPin = 4;     // the number of the pushbutton pin
const int green_ledPin =  6; 

// variables will change:
int green_buttonState = 0;         // variable for reading the pushbutton status
int red_buttonState = 0; 

int cython_is_buzy = 0;
int red_is_buzy = 0;
int green_is_buzy = 0;
int red_request = 0;
int green_request = 0;


void pick(){
  
  cython_state.data = 1;
  cython.publish(&cython_state);
  nh.spinOnce();
  
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao inicial com a garra aberta
  delay(1000);
  Serial2.println("#7 P800 #6 P1500 #5 P2300 #4 P1500 #3 P2000 #2 P1500 #1 P1820 #0 P1500 T500 <cd> "); // Posicao Inicial 
  delay(500);
  Serial2.println("#7 P800 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1890 #0 P1500 T500 <cd> "); // Posicao final 
  delay(1500);
  nh.spinOnce();
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1890 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao inicial com a garra aberta
  delay(1000);
  
  cython_state.data = 0;
  cython.publish(&cython_state);
  nh.spinOnce();
}

void drop_green(){
  cython_state.data = 1;
  cython.publish(&cython_state);
  nh.spinOnce();
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao inicial com a garra fechada 
  delay(1000);  
  Serial2.println("#7 P1600 #6 P1970 #5 P2150 #4 P1050 #3 P2130 #2 P1400 #1 P1600 #0 P2250 T1000 <cd> "); // gira sem baixar e ajeita a garra
  delay(1000);  
  Serial2.println("#7 P1600 #6 P1970 #5 P2150 #4 P1050 #3 P1950 #2 P1400 #1 P1990 #0 P2250 T1500 <cd> "); // abaixa 1 e 3
  delay(1500);
  nh.spinOnce();
  Serial2.println("#7 P900 #6 P1970 #5 P2150 #4 P1050 #3 P1950 #2 P1400 #1 P2010 #0 P2250 T1000 <cd> "); // fecha a garra 
  delay(1000);  
  Serial2.println("#7 P900 #6 P1970 #5 P2150 #4 P1050 #3 P2000 #2 P1400 #1 P1850 #0 P2250 T1000 <cd> "); // volta o 1 e o 3 
  delay(1000);  
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T2000 <cd> "); // Posicao final com garra fechada 
  delay(2000);
  cython_state.data = 0;
  cython.publish(&cython_state);
  nh.spinOnce();  
}

void drop_red(){
  
  cython_state.data = 1;
  cython.publish(&cython_state);
  nh.spinOnce();
  Serial2.println("#7 P1500 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1500 #6 P1500 #5 P2230 #4 P1500 #3 P2110 #2 P1500 #1 P1600 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  nh.spinOnce();
  Serial2.println("#7 P1500 #6 P1500 #5 P2230 #4 P1500 #3 P2110 #2 P1500 #1 P1830 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1500 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1890 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  nh.spinOnce();
  Serial2.println("#7 P900 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1890 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P900 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1600 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  nh.spinOnce();
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);  
  cython_state.data = 0;
  cython.publish(&cython_state);
  nh.spinOnce();
  
}

void drop_ready(){
  cython_state.data = 1;
  cython.publish(&cython_state);
  nh.spinOnce();
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P2000 #3 P2130 #2 P1500 #1 P1800 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P2000 #3 P2130 #2 P1500 #1 P1800 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(2500);
  cython_state.data = 0;
  cython.publish(&cython_state);
  nh.spinOnce();  
}

void pick_green(){  
  
  cython_state.data = 1;
  cython.publish(&cython_state);
  nh.spinOnce();
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao inicial com a garra aberta
  delay(1000);  
  Serial2.println("#7 P900 #6 P1970 #5 P2150 #4 P1050 #3 P2130 #2 P1400 #1 P1600 #0 P2250 T1000 <cd> "); // gira sem baixar e ajeita a garra
  delay(1000); 
  nh.spinOnce(); 
  Serial2.println("#7 P900 #6 P1970 #5 P2150 #4 P1050 #3 P1950 #2 P1400 #1 P1990 #0 P2250 T1000 <cd> "); // abaixa 1 e 3
  delay(1000);
  nh.spinOnce();
  Serial2.println("#7 P1700 #6 P1970 #5 P2150 #4 P1050 #3 P1950 #2 P1400 #1 P2010 #0 P2250 T1000 <cd> "); // fecha a garra 
  delay(1000);  
  Serial2.println("#7 P1700 #6 P1970 #5 P2150 #4 P1050 #3 P2000 #2 P1400 #1 P1850 #0 P2250 T1000 <cd> "); // volta o 1 e o 3 
  delay(1000); 
  nh.spinOnce(); 
  Serial2.println("#7 P1700 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  cython_state.data = 0;
  cython.publish(&cython_state);
  nh.spinOnce();
 
}

void pick_red(){
  
  cython_state.data = 1;
  cython.publish(&cython_state);
  nh.spinOnce();  
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P900 #6 P1500 #5 P2230 #4 P1500 #3 P2110 #2 P1500 #1 P1600 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  nh.spinOnce();
  Serial2.println("#7 P900 #6 P1500 #5 P2230 #4 P1500 #3 P2110 #2 P1500 #1 P1830 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P900 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1910 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  nh.spinOnce();
  Serial2.println("#7 P1600 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1910 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1600 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1910 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  nh.spinOnce();
  
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
  
  
  if (pose.data == 1){
    
    if (green_is_buzy == 0) { 
      digitalWrite(green_ledPin, HIGH);
      pick();
      drop_green();
      green_is_buzy = 1;
      nh.spinOnce();
      cython.publish(&cython_state);
       
    }
    
  }

  if (pose.data == 2){
    
    if (red_is_buzy == 0) { 
      digitalWrite(red_ledPin, HIGH);
      pick();
      drop_red();
      red_is_buzy = 1;
      nh.spinOnce();
      cython.publish(&cython_state);
       
    }
    
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
  pinMode(red_ledPin, OUTPUT);
  pinMode(green_ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(red_buttonPin, INPUT);
  pinMode(green_buttonPin, INPUT);
  nh.getHardware()->setBaud(57600);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(cython);
  Serial2.begin(9600);
  initial_position();
  
}

void loop()
{ 
  green_buttonState = digitalRead(green_buttonPin);
  if (green_buttonState == HIGH) {
     green_request = 1;
  } 

  red_buttonState = digitalRead(red_buttonPin);

  if (red_buttonState == HIGH) {
    // turn LED on:
    red_request = 1;
  }
  
  if (red_request == 1) {
    digitalWrite(red_ledPin, HIGH);
    
      if (cython_state.data == 0){
        pick_red();        
        drop_ready();
        nh.spinOnce();
        red_request = 0;
        red_is_buzy = 0;
        digitalWrite(red_ledPin, LOW);
      }   
  }

  if (green_request == 1) {
    
      if (cython_state.data == 0){
        pick_green();        
        drop_ready();
        nh.spinOnce();
        green_request = 0;
        green_is_buzy = 0;
        digitalWrite(green_ledPin, LOW);
      }   
  }
  
  //cython_state.data = 0;
  nh.spinOnce();
  delay(10);
   
}

