// Define pin connections & motor's steps per revolution
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200; 

const int sensor = A0 ;

int speedUpButton=6 ;
int speedDownButton=7 ;
int startDuration = 3000 ;

int autoModButton=5 ;
int manuelModButton=9 ;

void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
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
      if (duration > 2000) {
      duration -= 1000 ;
      }
  }
   if (speedDownButton == HIGH){
      if (duration < 4000) {
      duration += 1000 ;
      }
  }

  // ----> Mod select
  int autoModButtonState=digitalRead(autoModButton);
  int manuelModButtonState=digitalRead(manuelModButton);
  int level=analogRead(sensor);

  if (autoModButtonState == HIGH){ // ----> Auto Mod

      if (level > 500){ // Sound Level 

        for(int x=1;x<=10;x++){ // Number of Laps

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
       delay(10000); 
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