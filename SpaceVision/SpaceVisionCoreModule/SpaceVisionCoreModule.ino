#include <MPU6050_tockn.h> //gyro sensor library
#include <Wire.h>

MPU6050 mpu6050(Wire);
int buzzerPin = 9;

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Use pins 10 and 11 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 10; // Connects to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true); //calculation of gyro sensor offsets
  pinMode(buzzerPin, OUTPUT);
  softwareSerial.begin(9600);
  // Start communication with DFPlayer Mini
  
  if (player.begin(softwareSerial)) 
  {
   Serial.println("OK");
  } 
  
  else 
  {
    Serial.println("Connecting to DFPlayer Mini failed! Spinkame.");
  }
}

void loop() 
{
  mpu6050.update(); //updating the gyro coordinates constantly
  printAngles(); 
  checkYAngle();
  checkXAngle();
}

void printAngles() //demonstration/debugging purposes
{
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
}

void checkYAngle() //forwards and backwards
{
  if (mpu6050.getAngleY()<-30)
  {
      player.volume(30);
      player.play(2);
      tone(buzzerPin, 1000);
  }
  else if (mpu6050.getAngleY()>-10)
  {
      player.volume(30);
      player.play(2);
      tone(buzzerPin, 1000);
  }
  else
  {
      noTone(buzzerPin);
  }
}

void checkXAngle() //right and left
{
  if (mpu6050.getAngleX()<-20)
  {
      player.volume(30);
      player.play(2);
      tone(buzzerPin, 1000);
  }
  else if (mpu6050.getAngleX()>20)
  {
      player.volume(30);
      player.play(2);
      tone(buzzerPin, 1000);
  }
  else
  {
      noTone(buzzerPin);
  }
}
