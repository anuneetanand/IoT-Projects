#include<LiquidCrystal.h>
const int RS=6,EN=7;
int s=0;
int F=0;
int L=0;
int defbright=150;
LiquidCrystal LCD(RS,EN,5,4,3,2);

void setup() 
{
LCD.begin(16,2);
Serial.begin(9600);
LCD.setCursor(0,0);
pinMode(8,INPUT);
pinMode(9,OUTPUT);  
pinMode(10,OUTPUT);
}

void loop() 
{
 s=digitalRead(8);
 
 if (s== LOW)    // Proximity of 10cm.
 {
  LCD.setCursor(0,0);
  analogWrite(10,defbright);
  LCD.print("WELCOME");
  digitalWrite(9,HIGH);   //Send to Vcc of other arduino.
  Serial.println(F);
  //Serial.println("L"+L);
  if(F)
  {
    L=0;
    LCD.clear();
    LCD.print("Fan Speed: ");
    delay(1000);
  }

  if(L)
  {
    F=0;
    L=L-5;
    LCD.clear();
    LCD.print("Brightness: ");
    delay(1000);
  }  
 }

 else
 {
  LCD.print("SLEEP MODE");
  delay(3000);
  LCD.clear();
 }
 F=analogRead(A0);
 L=analogRead(A1);

}
