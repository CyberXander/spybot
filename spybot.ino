#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<SoftwareSerial.h>

#define BLYNK_AUTH_TOKEN  "IwQncX5kXDhIwKGdsUfA3L-lArcUig0e"

char auth[] = BLYNK_AUTH_TOKEN; //my token
// Your WiFi credentials.
char ssid[] = "CYBERX"; //YourNetworkName
char pass[] = "cyberxander"; //YourPassword
BlynkTimer timer;


int ax ,ay;
int gout =D2;

BLYNK_WRITE(V1) {
 ax = param[0].asInt();
 ay = param[1].asInt();
// x =  -10,10   
// Y =  -10,10
}
void gassense()
{
  if( digitalRead(gout)==LOW) {
  //digitalWrite(3, HIGH);
  Blynk.notify("GAS DETECTED");
  delay(300); 
  }
else
{
}


          
}
void value(int x,int y)
{
if ((x==0) && (y==0)) // stop
{
  Serial1.println("stop00");
  Serial.println("1");
  
           //movement(0,LOW,LOW,0,LOW,LOW); 
}
else if ((x>-4)&&(x<4)&&(y>=3)) // forwSerial 
{
        
            Serial1.println("forwSerial ");
  Serial.println("2");
}
else if ((x>-4)&&(x<4)&&(y<=-3)) // backwSerial
{ 
            Serial1.println("back");
  Serial.println("3");
}
else if ((y>=-4) && (y<=4) && (x<=-3)) //sharp left 
    {      Serial1.println("sl");
  Serial.println("4");
    }
else if ((x<-4)&&(y>4)) //forwSerial.println(); left 
      {     Serial1.println("forwSerial left");
              Serial.println(5);
      }
else if ((x>4)&&(y>4)) //forwSerial.println(); right 
{            Serial1.println("fR");
  Serial.println("6");
}
else if ((y>=-4) && (y<=4) && (x>=3)) // sharp right 
 {                       Serial1.println("sr");
  Serial.println("7");
 
            
            } 
else if ((x<-4)&&(y<-4)) //backwSerial left 
{            Serial1.println("bL");
  Serial.println("8");
}

 else if ((x>4)&&(y<-4)) //BACKWSerial right 
 { 
            Serial1.println("bR");
  Serial.println("9");
 }
 delay(300);
}


void setup() {
  //pinMode(3,OUTPUT );
  
 Serial1.begin(115200);
 Serial.begin(115200);
 
 Blynk.begin(auth, ssid, pass, IPAddress(192,168,43,25),8080);
//servo.attach(2);//D4
pinMode(gout, INPUT);
//Blynk.begin(auth, ssid, pass, IPAddress(192,168,43,78), 8080);
//timer.setTimer(400, value,400);
}
void loop() 
{
 Blynk.run();
 timer.run();
value(ax,ay);
gassense();
}
