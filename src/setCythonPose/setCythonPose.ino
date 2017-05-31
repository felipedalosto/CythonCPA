

#include <ros.h>
#include <std_msgs/Int8.h>

ros::NodeHandle  nh;

void messageCb( const std_msgs::Int8& pose){
   
  if (pose.data == 1){
    garra1();
  }

  if (pose.data == 2){
    garra();
  }
    
}

ros::Subscriber<std_msgs::Int8> sub("pose", &messageCb );
std_msgs::Int8 cython_state;
ros::Publisher cython("cython", &cython_state);

void garra(){
  
   Serial2.println("#7 P1300 #6 P1500 #5 P1500 #4 P1500 #3 P1500 #2 P1500 #1 P1500 #0 P1500 T1000 <cd> "); // Posicao Inicial 
   delay(3000);
   nh.spinOnce();
   Serial2.println("#7 P900 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P1900 #0 P1500 T1000 <cd>"); // Abaixa o braco
   delay(2000);
   Serial2.println("#7 P900 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P2100 #0 P1500 T1500 <cd>"); // Abaixa mais o braco
   delay(2000);
   nh.spinOnce(); 
   Serial2.println("#7 P1600 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P2100 #0 P1500 T750 <cd>"); // Fecha a garra
   delay(1000);  
   Serial2.println("#7 P1600 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P1900 #0 P1500 T1000 <cd>"); // Levanta o braço 
   delay(1000); 
   Serial2.println("#7 P1600 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P1900 #0 P2200 T1000 <cd>"); // Gira o braco (horario)
   delay(1000);
   nh.spinOnce();
   Serial2.println("#7 P1600 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P2000 #0 P2200 T750 <cd>"); // Abaixo o braço
   delay(1500);
   Serial2.println("#7 P900 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P2000 #0 P2200 T500 <cd>"); // Abre a garra
   delay(2000);
   
   cython.publish(&cython_state); 
   nh.spinOnce();   
}

void garra1(){
  
   Serial2.println("#7 P1300 #6 P1500 #5 P1500 #4 P1500 #3 P1500 #2 P1500 #1 P1500 #0 P1500 T1000 <cd> "); // Posicao Inicial 
   delay(3000);
   nh.spinOnce();
   Serial2.println("#7 P900 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P1900 #0 P1500 T1000 <cd>"); // Abaixa o braco
   delay(2000);
   Serial2.println("#7 P900 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P2100 #0 P1500 T1500 <cd>"); // Abaixa mais o braco
   delay(2000);
   nh.spinOnce(); 
   Serial2.println("#7 P1600 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P2100 #0 P1500 T750 <cd>"); // Fecha a garra
   delay(1000);  
   Serial2.println("#7 P1600 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P1900 #0 P1500 T1000 <cd>"); // Levanta o braço 
   delay(1000); 
   Serial2.println("#7 P1600 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P1900 #0 P800 T1000 <cd>"); // Gira o braco (horario)
   delay(1000);
   nh.spinOnce();
   Serial2.println("#7 P1600 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P2000 #0 P800 T750 <cd>"); // Abaixo o braço
   delay(1500);
   Serial2.println("#7 P900 #6 P1500 #5 P2250 #4 P1500 #3 P1900 #2 P1500 #1 P2000 #0 P800 T500 <cd>"); // Abre a garra
   delay(2000);   
   
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
  
}

void loop()
{  
  cython_state.data = 1;
  nh.spinOnce();
  delay(10);
   
}

