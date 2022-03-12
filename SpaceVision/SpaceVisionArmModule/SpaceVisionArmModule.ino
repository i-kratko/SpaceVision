#include <HCSR04.h>

int trigPin = 7;
int echoPin = 9;
int buzzerPin = 6;
int distance;
int frequency;
int vibrationPin = 2;

//initializing the ultra sonic sensor
HCSR04 ultrasonic(trigPin, echoPin);

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(vibrationPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() 
{
  //Serial.print("Distance: ");
  //Serial.println(ultrasonic.dist());
  //the same thing -> printOutDistance()

  //calling the function
  printOutDistance();
  
  if (ultrasonic.dist() < 40)
  {
      //turns on the vibration module
      digitalWrite(vibrationPin, HIGH);
      delay(60);
  }
  else
  {
    //turns off the vibration module
    digitalWrite(vibrationPin, LOW);
    delay(60);
  }
}

//this is the function that prints out the distance
//mesured by the ultrasonic sensor to the 
//serial monitor
void printOutDistance()
{
  Serial.print("Distance: ");
  Serial.println(ultrasonic.dist());
}
