#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;
const int potPin = A0;

// Variable
int sensorValue = 0;
File dataFile;

void setup() {
  // Begin Serial Monitor
  Serial.begin(9600);

  // Initialize SD card
  Serial.println("Initializing SD Card...");
  SD.begin(chipSelect);
   if (SD.begin(chipSelect)){
    Serial.println("SD Card Found");
  } else {
  Serial.println("SD Card Not Found");
  }
  
  // Open sensor.txt
  dataFile = SD.open("sensor.csv", FILE_WRITE);

  //Create Header
  dataFile.println("Time,Value");
  dataFile.close();
}
 
void loop() {
  // Measure Pot & Time
  int potVal = analogRead(A0);
  unsigned long time = millis()/1000;

  //Open CSV File
  dataFile = SD.open("sensor.csv", FILE_WRITE);

  //Write Time & Pot
  dataFile.print(time);
  dataFile.print(",");
  dataFile.println(potVal);
  //Save changes
  dataFile.close();
  Serial.println("Time Printed");
  delay(1000);
}