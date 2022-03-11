
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
<<<<<<< HEAD
int backBuzzerPin = 9;
=======

int backBuzzer = 9;

//we work with y and z

>>>>>>> ef9b709c5ad80b7888e644e2030bc875811c682f
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(backBuzzerPin, OUTPUT);
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
      tone(backBuzzerPin, 100);
  }
  else if (mpu6050.getAngleY()>20)
  {
      tone(backBuzzerPin, 100);
  }
  else 
  {
      noTone(backBuzzerPin);
  }
}
