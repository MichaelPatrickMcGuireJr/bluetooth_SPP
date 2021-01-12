#include <SoftwareSerial.h> 


SoftwareSerial MyBlue(10, 11); // RX | TX 

char* receive_msg;
 
void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 //pinMode(LED, OUTPUT); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
  

  
 if (MyBlue.available()) 
 {
    
    //receive_msg = receive_msg + MyBlue.read(); 
    char x = MyBlue.read();
    Serial.println( x );
      
 }
 else
 {
    char* f = "hello world!!\n\r";
    MyBlue.write(f);
    Serial.println("sent message");
 }


 delay(500);
}  
