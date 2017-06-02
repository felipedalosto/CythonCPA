void setup() {
  Serial2.begin(9600);
  
  //Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T2000 <cd> "); // Posicao final 
  //delay(2000);
 Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000); 
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P2000 #3 P2130 #2 P1500 #1 P1800 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P2000 #3 P2130 #2 P1500 #1 P1800 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  //drop_ready();
  //pick_green();
  //drop_green();
  /*pick_red();
  drop_red();*/
    
}

void loop() {
  // put your main code here, to run repeatedly:
  //pick();
}

void drop_ready(){  
  
  
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao inicial 
  delay(1000); 
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000); 
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000);
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P2000 #3 P2130 #2 P1500 #1 P1800 #0 P2300 T1000 <cd> "); // Posicao inicial 
  delay(1000); 
  
}

void pick_green(){  
  
  
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao inicial 
  delay(1000);  
  Serial2.println("#7 P900 #6 P1970 #5 P2150 #4 P1050 #3 P2130 #2 P1400 #1 P1600 #0 P2250 T1000 <cd> "); // gira sem baixar e ajeita a garra
  delay(1000);  
  Serial2.println("#7 P900 #6 P1970 #5 P2150 #4 P1050 #3 P1950 #2 P1400 #1 P1990 #0 P2250 T1000 <cd> "); // abaixa 1 e 3
  delay(1000);
  Serial2.println("#7 P1600 #6 P1970 #5 P2150 #4 P1050 #3 P1950 #2 P1400 #1 P2010 #0 P2250 T1000 <cd> "); // fecha a garra 
  delay(1000);  
  Serial2.println("#7 P1600 #6 P1970 #5 P2150 #4 P1050 #3 P2000 #2 P1400 #1 P1850 #0 P2250 T1000 <cd> "); // volta o 1 e o 3 
  delay(1000);  
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T2000 <cd> "); // Posicao final com garra fechada 
  delay(2000);
 
}

void drop_green(){
  
  
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao inicial 
  delay(1000);  
  Serial2.println("#7 P900 #6 P1970 #5 P2150 #4 P1050 #3 P2130 #2 P1400 #1 P1600 #0 P2250 T1000 <cd> "); // gira sem baixar e ajeita a garra
  delay(1000);  
  Serial2.println("#7 P900 #6 P1970 #5 P2150 #4 P1050 #3 P1950 #2 P1400 #1 P1990 #0 P2250 T1000 <cd> "); // abaixa 1 e 3
  delay(1000);
  Serial2.println("#7 P1600 #6 P1970 #5 P2150 #4 P1050 #3 P1950 #2 P1400 #1 P2010 #0 P2250 T1000 <cd> "); // fecha a garra 
  delay(1000);  
  Serial2.println("#7 P1600 #6 P1970 #5 P2150 #4 P1050 #3 P2000 #2 P1400 #1 P1850 #0 P2250 T1000 <cd> "); // volta o 1 e o 3 
  delay(1000);  
  Serial2.println("#7 P1600 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T2000 <cd> "); // Posicao final com garra fechada 
  delay(2000);
   
}

void pick_red(){
  
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P900 #6 P1500 #5 P2230 #4 P1500 #3 P2110 #2 P1500 #1 P1600 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P900 #6 P1500 #5 P2230 #4 P1500 #3 P2110 #2 P1500 #1 P1830 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P900 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1890 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1500 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1890 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1500 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1600 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1500 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
}

void drop_red(){
  
  Serial2.println("#7 P1500 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1500 #6 P1500 #5 P2230 #4 P1500 #3 P2110 #2 P1500 #1 P1600 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1500 #6 P1500 #5 P2230 #4 P1500 #3 P2110 #2 P1500 #1 P1830 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P1500 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1890 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P900 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1890 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P900 #6 P1500 #5 P2210 #4 P1500 #3 P2110 #2 P1500 #1 P1600 #0 P2270 T1000 <cd> "); // Posicao final 
  delay(1500);
  Serial2.println("#7 P900 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);
}


void initial_position(){
  
  //Serial2.println("#7 P1700 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1500 <cd> "); // Posicao final 
  delay(1500);
  
}

void drop_left(){
  
  Serial2.println("#7 P1700 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P2100 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P1700 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P2100 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P1100 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P2100 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P1700 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);  
  
}

void drop_right(){
  
  Serial2.println("#7 P1700 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P900 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P1700 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P900 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P1100 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1870 #0 P900 T1000 <cd> "); // Posicao Inicial 
  delay(1000);
  Serial2.println("#7 P1700 #6 P1500 #5 P2150 #4 P1500 #3 P2130 #2 P1500 #1 P1600 #0 P1500 T1000 <cd> "); // Posicao final 
  delay(1500);  
  
}

