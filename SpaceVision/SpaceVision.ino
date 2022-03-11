int trigPin = 7;
int echoPin = 9;
int buzzerPin = 5;
int frequency;
int distance;
int duration;
#include <NewPing.h>
NewPing sonar;
void setup() 
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); 
}
void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = sonar.ping_cm();
 // frequency = map(2, 140, 0, 5000);
  //tone(buzzerPin, frequency;
  Serial.print("Distance: ");
  Serial.println(distance);
  
}
