const int snrL=12;
const int snrR=11;
const int snrF1=10;
const int snrF2=9;
const int mtrRF=3;
const int mtrRB=2;
const int mtrLF=4;
const int mtrLB=5;

int sRF=LOW;
int sRB=LOW;
int sLF=LOW;
int sLB=LOW;

void setup() {
  Serial.begin(9600);

  pinMode(snrR, INPUT);
  pinMode(snrL, INPUT);
  pinMode(snrF1, INPUT);
  pinMode(snrF2, INPUT);
  pinMode(mtrRF, OUTPUT);
  pinMode(mtrRB, OUTPUT);
  pinMode(mtrLF, OUTPUT);
  pinMode(mtrLB, OUTPUT);
}

void turnRight(int x){
  
  digitalWrite(mtrRF, LOW);
  digitalWrite(mtrRB, HIGH);
  digitalWrite(mtrLF, HIGH);
  digitalWrite(mtrLB, LOW);
  delay(x);

}

void turnLeft(int x){
  
  digitalWrite(mtrRF, HIGH);
  digitalWrite(mtrRB, LOW);
  digitalWrite(mtrLF, LOW);
  digitalWrite(mtrLB, HIGH);
  delay(x);

}

void goForward(int x){
  
  digitalWrite(mtrRF, HIGH);
  digitalWrite(mtrRB, LOW);
  digitalWrite(mtrLF, HIGH);
  digitalWrite(mtrLB, LOW);
  delay(x);

}

void goBackward(int x){
  
  digitalWrite(mtrRF, LOW);
  digitalWrite(mtrRB, HIGH);
  digitalWrite(mtrLF, LOW);
  digitalWrite(mtrLB, HIGH);
  delay(x);

}

void brake(int x){
    digitalWrite(mtrRF, LOW);
    digitalWrite(mtrRB, LOW);
    digitalWrite(mtrLF, LOW);
    digitalWrite(mtrLB, LOW);
    delay(x); 
}

void loop() {
  
  if(digitalRead(snrF1) == 1 && digitalRead(snrF2) == 1) {
    goForward(1);
  }
  else if(digitalRead(snrF1) == 1 && digitalRead(snrF2 == 0)){
    while(digitalRead(snrF1)!=0){
      turnRight(1);
    }
  goBackward(700);
    if (digitalRead(snrL) == 1){
      turnLeft(600);
    }
    else {
      if (digitalRead(snrR) == 1){
        turnRight(600);
      }
      else{
        goBackward(4000);
      }
    }
  }
  else if(digitalRead(snrF1) == 0 && digitalRead(snrF2 == 1)){
    while(digitalRead(snrF2)!=0){
      turnLeft(1);
    }
    goBackward(700);
    if (digitalRead(snrL) == 1){
      turnLeft(600);
    }
    else {
      if (digitalRead(snrR) == 1){
        turnRight(600);
      }
      else{
        goBackward(4000);
      }
    }
  }
  else{
    goBackward(700);
    if (digitalRead(snrL) == 1){
      turnLeft(600);
    }
    else {
      if (digitalRead(snrR) == 1){
        turnRight(600);
      }
      else{
        goBackward(4000);
      }
    }

  }

  /*
  Serial.print("Motor");
  Serial.print(sRF);
  Serial.print(sRB);
  Serial.print(sLF);
  Serial.print(sLB);
  Serial.print("\t Sensor");
  Serial.print(digitalRead(snrL));
  Serial.print(digitalRead(snrR));
  Serial.print(digitalRead(snrF1));
  Serial.println(digitalRead(snrF2));

  delay(100);

  */
}