#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);  //Bluetooth
int tf=0;
char s=0;
int df=0;
int tl=0;
int dl=0;
int F=0;
int L=0;
int Fb=0;
int Lb=0;

void setup()
{
  
BT.begin(38400);
//Use pin 9 of other arduino as Vcc.

//LEDs
pinMode(2,OUTPUT);  //Fan
pinMode(3,OUTPUT);

pinMode(8,OUTPUT);  //Lamp
pinMode(9,OUTPUT);

//Sensors

pinMode(4,OUTPUT);
pinMode(5,INPUT);  //Fan

pinMode(6,OUTPUT);
pinMode(7,INPUT);  //Lamp

//Devices
pinMode(A0,OUTPUT); //Fan
pinMode(A1,OUTPUT); //Lamp

}

void loop() 
{

 digitalWrite(2,HIGH);  //Red
 digitalWrite(8,HIGH);  //Red

 digitalWrite(4,LOW);
 digitalWrite(6,LOW);
 delayMicroseconds(2);
 
 digitalWrite(4,HIGH);
 delayMicroseconds(10);
 digitalWrite(4,LOW);;
 tf=pulseIn(5,HIGH);
 df=tf*0.017;

 digitalWrite(6,HIGH);
 delayMicroseconds(10);
 digitalWrite(6,LOW);;
 tl=pulseIn(7,HIGH);
 dl=tl*0.017;

 //Implement Conversions

 if((df<60)&&(df>20))
 {
  pinMode(2,LOW);
  pinMode(3,HIGH);  //Green
  F=int(df/10)-1;
  BT.write(F);
  analogWrite(A0,F);  //Bluetooth + P10
 }
 else
 {
  analogWrite(A0,0);
 }
 
 if((dl<60)&&(dl>20))
 {
  pinMode(8,LOW);
  pinMode(9,HIGH);  //Green
  L=int(dl/10)+3;
  BT.write(L);
  analogWrite(A1,L);  //Bluetooth + P11
 }
 else
 {
  analogWrite(A1,0);
 }

}
