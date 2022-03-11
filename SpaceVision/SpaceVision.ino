#include <HCSR04.h>

int trigPin = 7;
int echoPin = 9;
int buzzerPin = 6;
int distance;
int frequency;
int vibrationPin = 2;

HCSR04 ultrasonic(trigPin, echoPin);

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(vibrationPin, OUTPUT);
  Serial.begin(9600); 
}
void loop() 
{
  Serial.print("Distance: ");
  Serial.println(ultrasonic.dist());
  if (ultrasonic.dist() < 30)
  {
      digitalWrite(vibrationPin, HIGH);
      delay(60);
  }
  else
  {
    digitalWrite(vibrationPin, LOW);
    //delay(60);
  }
}
