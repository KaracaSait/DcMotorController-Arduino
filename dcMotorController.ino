// Define pin connections & motor's steps per revolution
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200; 

const int sensor = A0 ;

int startDuration = 1500 ;

// Button Pins
int speedUpButton=6 ;
int speedDownButton=7 ;
int autoModButton=5 ;
int manuelModButton=8 ;
// Led Pins
int ledOne=9;
int ledTwo=10;
int ledThree=11;

void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(ledOne,OUTPUT);
  pinMode(ledTwo,OUTPUT);
  pinMode(ledThree,OUTPUT);
  // Declare pins as Inputs
  pinMode(speedUpButton,INPUT);
  pinMode(speedDownButton,INPUT);
  pinMode(autoModButton,INPUT);
  pinMode(manuelModButton,INPUT);
}
void loop()
{
  
  // ----> Speed Settings

  static int duration = startDuration;
  
  int speedUpButtonState=digitalRead(speedUpButton);
  int speedDownButtonState=digitalRead(speedDownButton);

  if (speedUpButtonState == HIGH){

      if (duration > 1000) {
      duration -= 500 ;
      delay(200);
      }
  }
   if (speedDownButtonState == HIGH){

      if (duration < 2500) {
      duration += 500 ;
      delay(200);
      }

  }

  // ----> Led Settings
  
  if (duration == 1000){
    digitalWrite(ledOne,HIGH);
    digitalWrite(ledTwo,HIGH);
    digitalWrite(ledThree,HIGH);
  }else if (duration == 1500){
    digitalWrite(ledOne,HIGH);
    digitalWrite(ledTwo,HIGH);
    digitalWrite(ledThree,LOW);
  }else if (duration == 2000){
    digitalWrite(ledOne,HIGH);
    digitalWrite(ledTwo,LOW);
    digitalWrite(ledThree,LOW);
  }else if (duration == 2500){
    digitalWrite(ledOne,LOW);
    digitalWrite(ledTwo,LOW);
    digitalWrite(ledThree,LOW);
  }

  // ----> Mod select
  int autoModButtonState=digitalRead(autoModButton);
  int manuelModButtonState=digitalRead(manuelModButton);
  int level=analogRead(sensor);

  unsigned long baslangicZamani = millis(); // ----> Time Settings

  if (autoModButtonState == HIGH){ // ----> Auto Mod

      if (level > 1000){ // Sound Level 

        for (unsigned long gecenZaman = 0; gecenZaman < 300000; gecenZaman = millis() - baslangicZamani) { // ----> Time Settings (5 Min) 
    
        digitalWrite(dirPin, LOW); // Set motor direction clockwise

        // Spin motor
        for(int x = 0; x < stepsPerRevolution; x++)
        {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(duration); 
          digitalWrite(stepPin, LOW);
          delayMicroseconds(duration); 
        }
        delay(50); 
        digitalWrite(dirPin, HIGH); // Set motor direction counterclockwise

        // Spin motor
        for(int x = 0; x < stepsPerRevolution; x++)
        {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(duration); 
          digitalWrite(stepPin, LOW);
          delayMicroseconds(duration); 
        }
        delay(50); 
      }
       delay(60000); // ----> Waiting Time
      }

  }else if (manuelModButtonState == HIGH){ // ----> Manuel Mod

  digitalWrite(dirPin, LOW); // Set motor direction clockwise

  // Spin motor
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(duration); 
    digitalWrite(stepPin, LOW);
    delayMicroseconds(duration); 
  }
  delay(50); 
  digitalWrite(dirPin, HIGH); // Set motor direction counterclockwise

  // Spin motor
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(duration); 
    digitalWrite(stepPin, LOW);
    delayMicroseconds(duration); 
  }
  delay(50);
  }
  
}