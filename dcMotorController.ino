// Define pin connections & motor's steps per revolution
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200; 

int led=11 ;
int speedUpButton=5 ;
int speedDownButton=9 ;
int startDuration = 3000 ;

void setup()
{
  // Declare pins as Outputs
  pinMode(led, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  // Declare pins as Inputs
  pinMode(speedUpButton,INPUT);
  pinMode(speedDownButton,INPUT);
}
void loop()
{

  static int duration = startDuration;

  int speedUpButtonState=digitalRead(speedUpButton);
  int speedDownButtonState=digitalRead(speedDownButton);

  if (speedUpButtonState == HIGH){
    if (duration > 2000) {
    duration -= 1000 ;
    digitalWrite(led,HIGH);
    }
  }else {
    digitalWrite(led,LOW);
  }

   if (speedDownButton == HIGH){
    if (duration < 4000) {
    duration += 1000 ;
    digitalWrite(led,HIGH);
    }
  }else {
    digitalWrite(led,LOW);
  }

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