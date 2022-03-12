
#include <MPU6050_tockn.h> //gyro sensor library
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <Wire.h>

SoftwareSerial softwareSerial(10, 11);
DFRobotDFPlayerMini mp3Player;
MPU6050 mpu6050(Wire);
int buzzerPin = 9;

void setup() 
{
  softwareSerial.begin(9600);
  mp3Player.begin(softwareSerial);
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);  //calculation of gyro sensor offsets
  pinMode(buzzerPin, OUTPUT);
}

void loop() 
{
  mpu6050.update(); //updating the gyro coordinates constantly
  printAngles(); 
  checkYAngle();
  checkXAngle();
  Serial.println(myDFPlayer.readState()); //read mp3 state
  Serial.println(myDFPlayer.readVolume()); //read current volume
  Serial.println(myDFPlayer.readEQ()); //read EQ setting
  Serial.println(myDFPlayer.readFileCounts()); //read all file counts in SD card
  Serial.println(myDFPlayer.readCurrentFileNumber()); //read current play file number
  Serial.println(myDFPlayer.readFileCountsInFolder(3)); //read file counts in folder SD:/03
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
  if (mpu6050.getAngleY()<-40)
  {
      mp3Player.playMp3Folder(1);
  }
  else if (mpu6050.getAngleY()>20)
  {
      mp3Player.playMp3Folder(2);
  }
}

void checkXAngle() //right and left
{
  if (mpu6050.getAngleX()<-30)
  {
      mp3Player.playMp3Folder(4);
  }
  else if (mpu6050.getAngleX()>30)
  {
      mp3Player.playMp3Folder(3);
  }
}
