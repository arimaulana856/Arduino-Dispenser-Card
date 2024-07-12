const int M_P1 = 10;
const int M_P2 = 9; 
const int M_P3 = 7;
const int M_P4 = 6;
//motor dc pengeluar kartu
const int M_P5 = 12;
const int M_P6 = 13;
int bt2 = 4;
int bt4 = 3;
int bt6 = 2;
int bt8 = 1;
const int buzz = 11;

void stop(){
  digitalWrite(M_P1, LOW);
  digitalWrite(M_P2, LOW);
  digitalWrite(M_P3, LOW);
  digitalWrite(M_P4, LOW);
}

void runRight(){
  digitalWrite(M_P1, HIGH);
  digitalWrite(M_P2, LOW);
  digitalWrite(M_P3, LOW);
  digitalWrite(M_P4, HIGH);
}

void stopCard(){
  digitalWrite(M_P5, LOW);
  digitalWrite(M_P6, LOW);
}

void outputCard(){
  digitalWrite(M_P5, LOW);
  digitalWrite(M_P6, HIGH);
}

void twoPlayer(){
  for(int a = 1; a <= 2; a++){
  //membagi kartu 
  tone(buzz, 2000);
  outputCard();
  delay(1000);
  noTone(buzz);
  stopCard();
  delay(1000);
        
  //berputar
  runRight();
  tone(buzz, 1000);
  delay(1000);   
  stop();
  noTone(buzz);
  delay(1000); 
    
  }
     
}

void fourPlayer(){
  for(int a = 1; a <= 4; a++){
  //membagi kartu 
  tone(buzz, 2000);
  delay(1000);
  noTone(buzz);
  delay(1000);
        
  //berputar
  runRight();
  tone(buzz, 1000);
  delay(1000);   
  stop();
  noTone(buzz);
  delay(1000); 
    
  }
     
}

void selPy(int count){
    for(int i = 1; i <= count; i++){
      if(i == 2){
        twoPlayer();
        
      }else if(i == 4){
        fourPlayer();
      }
  }
}


void setup(){
  Serial.begin(9600);
  pinMode(M_P1, OUTPUT);
  pinMode(M_P2, OUTPUT);
  pinMode(M_P3, OUTPUT);
  pinMode(M_P4, OUTPUT);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(bt4, INPUT_PULLUP);
  pinMode(bt6, INPUT_PULLUP);
  pinMode(bt8, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
  
  
}

void loop(){
  Serial.println(digitalRead(bt2),digitalRead(bt4));
  delay(500);
  
  if(digitalRead(bt2) == 0){
  	selPy(2);
  }else if(digitalRead(bt4) == 0){
    selPy(4);
  }else if(digitalRead(bt6) == 0){
    selPy(6);
  }else if(digitalRead(bt8) == 0){
    selPy(8);
  }
    

}