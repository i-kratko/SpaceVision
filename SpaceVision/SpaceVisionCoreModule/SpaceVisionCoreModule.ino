
#include <MPU6050_tockn.h>
#include <Wire.h>

//da se prepravi

MPU6050 mpu6050(Wire);
int backBuzzerPin = 9;
int rightBuzzerPin = 6;
int leftBuzzerPin = 5;
int frontBuzzerPin = 10;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(backBuzzerPin, OUTPUT);
  pinMode(rightBuzzerPin, OUTPUT);
  pinMode(leftBuzzerPin, OUTPUT); 
  pinMode(frontBuzzerPin, OUTPUT); 
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
  if (mpu6050.getAngleY()<-40)
  {
      tone(frontBuzzerPin, 100);
  }
  else if (mpu6050.getAngleY()>20)
  {
      tone(backBuzzerPin, 100);
  }
  else 
  {
      noTone(backBuzzerPin);
      noTone(frontBuzzerPin);
  }
  if (mpu6050.getAngleX()<-30)
  {
      tone(rightBuzzerPin, 100);
  }
  else if (mpu6050.getAngleX()>30)
  {
      tone(leftBuzzerPin, 100);
  }
  else 
  {
      noTone(rightBuzzerPin);
      noTone(leftBuzzerPin);
  }
}
