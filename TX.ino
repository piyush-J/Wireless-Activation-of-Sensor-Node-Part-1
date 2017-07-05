/* Date: 12-07-2016
 * 
 * Ground Station with a sensor (Real time data transmission)
 * 
 * Developed by: Piyush Jha, 1st Year B.Tech (completed)
 * Electronics and Communication Engineering, Malviya National Institute of Technology Jaipur 
 * 
 */

int sensorPin = 8;    
int sensorValue=0;
String sVstr;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {

  digitalWrite(13,LOW);
  delay(1000);
  sensorValue= digitalRead(sensorPin);  //read value from sensor
  sVstr=(sensorValue)?"T":"F";  
  Serial.print(sVstr);    //transfer through Zigbee/XBee
  digitalWrite(13,HIGH);  //LED on arduino blinks confirming successful transmission of data
  delay(1000);
}