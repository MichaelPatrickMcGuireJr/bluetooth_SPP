#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {

Serial.begin(9600);

//pinMode(9,OUTPUT); digitalWrite(9,HIGH);

Serial.println("Enter AT commands:");

mySerial.begin(38400);

}

void loop()

{
  //delay(1000);
  //mySerial.write("AT\r\n");
if (mySerial.available())
{ 
  Serial.write(mySerial.read());
  //Serial.write("d");
}
if (Serial.available())
{
  mySerial.write(Serial.read());
  //Serial.write("\r\n");
  //Serial.write("e");
}
}
