#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);
int F=0;
int L=0;
int B=0;

void setup() 
{
BT.begin(38400); 
pinMode(5,OUTPUT); //Fan
pinMode(6,OUTPUT); //Lamp
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
}

void loop() 
{

//Implement Bluetooth
if(BT.available()>0)
  B=BT.read()
if (B<5)
{
  F=B;
  tone(5,F*60);
  delay(1000);
  noTone(5);
}
else if (B<8)
{
  L=B-5;
  if(L==1)
  {
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  else  if(L==2)
  {
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
  }
  else if (L==3)
  {
    digitalWrite(8,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  else
  {
    digitalWrite(8,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
}
}
