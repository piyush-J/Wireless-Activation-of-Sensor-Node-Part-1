/* Date: 12-07-2016
 * 
 * Drone with an SD Card on it to receive and store the sensor data from the Ground Station
 * 
 * Developed by: Piyush Jha, 1st Year B.Tech (completed)
 * Electronics and Communication Engineering, Malviya National Institute of Technology Jaipur 
 * 
 */
 
#include <SD.h>
#include <SPI.h>
const int chipSelect = 4;

void setup()
{
 Serial.begin(9600);
 Serial.print("Initializing SD card...");
 pinMode(10, OUTPUT);                       //default
 if (!SD.begin(chipSelect)) {
 Serial.println("Card failed, or not present");
 return;
 }
 Serial.println("card initialized.");
}

void loop()
{
 String dataString = "";
 char datac;
 int data;
 if (Serial.available()>0)    //If data is being received from Zigbee/XBee
 {
 data=Serial.read();          //Read the data
 datac=char(data);
 dataString=String(datac);    //Required to convert to String to store in a txt file
 dataString+="\n";            //Append new line in the string

 File dataFile = SD.open("sensor1.txt", FILE_WRITE); 
 if (dataFile)                //If the file has been opened successfully
 {
  dataFile.print(dataString);
  dataFile.close();
  Serial.print(dataString);
 }
 else 
 {
  Serial.println("error opening datalog.txt");
 }
 }
}