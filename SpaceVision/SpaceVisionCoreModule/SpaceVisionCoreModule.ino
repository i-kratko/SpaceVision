
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
  Serial.begin(115200);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);  //calculation of gyro sensor offsets
  pinMode(buzzerPin, OUTPUT);
  
  if (!mp3Player.begin(softwareSerial)) 
  { 
    //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }

  mp3Player.volume(15);
  mp3Player.outputDevice(DFPLAYER_DEVICE_SD);
  mp3Player.play(1);

  Serial.println(mp3Player.readState()); //read mp3 state
  Serial.println(mp3Player.readVolume()); //read current volume
  Serial.println(mp3Player.readFileCounts()); //read all file counts in SD card
  Serial.println(mp3Player.readCurrentFileNumber()); //read current play file number
  Serial.println(mp3Player.readFileCountsInFolder(3)); //read file counts in folder SD:/03
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
  if (mpu6050.getAngleY()<-40)
  {
      mp3Player.playFolder(1,1);
  }
  else if (mpu6050.getAngleY()>20)
  {
      mp3Player.playFolder(2,1);
  }
}

void checkXAngle() //right and left
{
  if (mpu6050.getAngleX()<-30)
  {
      mp3Player.playFolder(4,1);
  }
  else if (mpu6050.getAngleX()>30)
  {
      mp3Player.playFolder(3,1);
  }
}
