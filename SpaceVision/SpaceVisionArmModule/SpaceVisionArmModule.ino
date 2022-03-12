#include <HCSR04.h> //ultrasonic library

int trigPin = 7;
int echoPin = 9;
int distance;
int vibrationPin = 2;

//initializing the ultra sonic sensor
HCSR04 ultrasonic(trigPin, echoPin);

void setup() 
{
  pinMode(vibrationPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() 
{
  Serial.print("Distance: ");
  Serial.println(ultrasonic.dist());
  //printOutDistance(); 
  if (ultrasonic.dist() < 40)
  {
      //powers on the vibration module
      digitalWrite(vibrationPin, HIGH);
      delay(60);
  }
  else
  {
      //powers off the vibration module
      digitalWrite(vibrationPin, LOW);
      //delay(60);
  }
}

/*this is the function that prints out the distance
mesured by the ultrasonic sensor to the 
serial monitor, for debugging*/
void printOutDistance()
{
  Serial.print("Distance: ");
  Serial.println(ultrasonic.dist());
}
