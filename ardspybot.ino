#include<SoftwareSerial.h>
SoftwareSerial ard(2,3);//Rx,Tx
const byte enA = 13; // ENA for motor drive
const byte motorA1 = 4; // in1 for motor drive
const byte motorA2 = 5; // in2 for motor drive
const byte motorB1 = 8; // in3 for motor drive
const byte motorB2 = 9; // in4 for motor drive
const byte enB = 12; // ENB for motor drive
//#define enA 500/*speed of motorA 
                 // and motorB*/
//#define enB 500


void movement( int prmA,byte prmA1, byte prmA2,int prmB, byte prmB1, byte prmB2)
{
 analogWrite(enA,prmA);
 analogWrite(enB,prmB);
 digitalWrite(motorA1,prmA1);
 digitalWrite(motorA2,prmA2);
 digitalWrite(motorB1,prmB1);
 digitalWrite(motorB2,prmB2);
 delay(200);
}

void setup() {
// Open serial communications and wait for port to open:
ard.begin(115200);
Serial.begin(115200);
 pinMode(motorA1,OUTPUT);
 pinMode(motorA2,OUTPUT);
 pinMode(motorB1,OUTPUT);
 pinMode(motorB2,OUTPUT);
digitalWrite(motorA1,LOW);
digitalWrite(motorA2,LOW);
digitalWrite(motorB1,LOW);
digitalWrite(motorB2,LOW);
//while (!Serial) {
//; // wait for serial port to connect. Needed for native USB port only
//}
}
void loop() { // run over and over
char i="";  
if (ard.available()) {
 i=ard.read();//direction from esp

if(i=='1')
{
movement(0,LOW,LOW,0,LOW,LOW); //stop
Serial.println("stp");
}
else if (i=='2'){
Serial.println("for");
movement(255,HIGH,LOW,255,HIGH,LOW); 
}
else if (i=='3'){
Serial.println("back");
  movement(255,LOW,HIGH,255,LOW,HIGH);
 }
 else if (i=='4'){
Serial.println("sl");
 movement(255,HIGH,LOW,255,LOW,HIGH);
 }
 else if (i=='5'){
Serial.println("left");
 movement(255,HIGH,LOW,130,HIGH,LOW);
 }
 
  else if (i=='6'){
Serial.println("right");
 movement(130,HIGH,LOW,255,HIGH,LOW); 
}
 else if (i=='7'){
Serial.println("sr");
 movement(255,LOW,HIGH,255,HIGH,LOW);
}

 else if (i=='8'){
Serial.println("bl");
 movement(130,LOW,HIGH,255,LOW,HIGH);
}
 else if (i=='9'){
Serial.println("br");
 movement(255,LOW,HIGH,130,LOW,HIGH);
}

}
}
