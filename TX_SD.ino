/* Date: 12-07-2016
 * 
 * Ground Station with SD Card (Data is cleared out after tranmission is completed successfully)
 * 
 * Developed by Piyush Jha, 1st Year B.Tech (completed)
 * Electronics and Communication Engineering, Malviya National Institute of Technology Jaipur 
 * 
 */

#include <SD.h>
#include <SPI.h>

const int chipSelect = 4;
File myFile;

void setup() {
 Serial.begin(9600);
 Serial.print("Initializing SD card...");
 pinMode(10, OUTPUT);
 // see if the card is present and can be initialized:
 if (!SD.begin(chipSelect)) {
 Serial.println("Card failed, or not present");
 return;
 }
 Serial.println("card initialized.");

 myFile = SD.open("test.txt");          //opening the text file
 if (myFile)                            
 {
    Serial.println("test.txt:");
    while (myFile.available()) // read from the file until there's nothing else in it:
    {
      Serial.write(myFile.read());  //transfer data through Zigbee/XBee
    }
    myFile.close();
    SD.remove("test.txt");  //removes the file after data transmission is completed
  } 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop() {
  //not required
}