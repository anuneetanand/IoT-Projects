//  AIR BEATS

//Notes:-
#include "pitches.h";
#include "pitches2.h";
//#define REST 1;

const int c4=261;
const int d4=294;
const int e4=329;
const int f4=349;
const int g4=392;
const int a4=440;
const int b4=494;
const int c4S=277;
const int d4S=311;
const int f4S=370;
const int g4S=415;
const int a4S=466;

int noteDuration;
int pauseBetweenNotes = 0;
int negra=640;

const int A =A3;  //Acclerometer
const int button1 =3;  //Thumb
const int button2 =13; //ForeFinger
const int button3 =11; //MiddleFinger
const int button4 =9;  //RingFinger
const int button5 =7;  //PinkyFinger
const int S  =6;  //Buzzer

void setup() 
{
Serial.begin(9600);
pinMode(A,INPUT);
pinMode(5,OUTPUT);
pinMode(3,INPUT);
pinMode(13,INPUT);
pinMode(11,INPUT);
pinMode(9,INPUT);
pinMode(7,INPUT);
pinMode(S,OUTPUT);
}

void loop() 
{
//  delay(2000);
  digitalWrite(5,LOW);
  int G=analogRead(A);
//  Serial.println("Orienation Reading:");
  Serial.println(G);
  //int X=map(G,1,3,260,420);
 // Serial.println("Orienation Mode:");
  //Serial.println(X);
  //delay(3000);
  int X;
  if (G<420){
    X=1;
  }else if(G<510){
    X=2;
  }else{
    X=3;
  }
  Serial.println(X);
  int Y1=digitalRead(button1);
  int Y2=digitalRead(button2);
  int Y3=digitalRead(button3);
  int Y4=digitalRead(button4);
  int Y5=digitalRead(button5);
  //Serial.println("hkdfshdskjdsk;dslhfdfhldhfdshfkhsdfhdskfhdshfhdskjs");
 // Serial.println(Y1);
//  Serial.println(Y2);
//  Serial.println(Y3);
//  Serial.println(Y4);
//  Serial.println(Y5);
  
//   Serial.println("hkdfshdskjdsk;dslhfdfhldhfdshfkhsdfhdskfhdshfhdskjs");
//  Serial.println(Y2);
//   Serial.println("hkdfshdskjdsk;dslhfdfhldhfdshfkhsdfhdskfhdshfhdskjs");
//  Serial.println(Y3);
//   Serial.println("hkdfshdskjdsk;dslhfdfhldhfdshfkhsdfhdskfhdshfhdskjs");
//  Serial.println(Y4);
//   Serial.println("hkdfshdskjdsk;dslhfdfhldhfdshfkhsdfhdskfhdshfhdskjs");
//  Serial.println(Y5);

  

Serial.println(X);
    play(X,Y1,Y2,Y3,Y4,Y5);
  
}

void play (int x,int C1,int C2,int C3, int C4,int C5){
    int count=0;
    int freq=0;
    if (x==2){
      if(C1==1){
        freq+=1100;
        count+=1;
      }
      if (C2==1){
        freq+=617;
        count+=1;
      }
      if (C3==1){
        freq+=824;
        count+=1;
      }
      if (C4==1){
        freq+=873;
        count+=1;
      }
      if (C5==1){
        freq+=980;
        count+=1;
      }
    }else if(x==1){
      if (C1==1){
        PT(C1);
      }
      if (C2==1){
        marioplay(13);
//        freq+=392;
//        count+=1;
      }
      if (C3==1){
        harrypotter(11);
//        freq+=440;
//        count+=1;
      }
      if (C4==1){
        jinglebells(9);
//        freq+=494;
//        count+=1;
      }
      if (C5==1){
        freq+=277;
        count+=1;
      }
    }else{
      if (C1==1){
        freq+=777;
        count+=1;
      }
      if (C2==1){
        freq+=311;
        count+=1;
      }
      if (C3==1){
        freq+=370;
        count+=1;
      }
      if (C4==1){
        freq+=415;
        count+=1;
      }
      if (C5==1){
        freq+=466;
        count+=1;
      }
    }
    if (count>0){
      tone(S,freq/count);
    }else{
      noTone(S);
    }
}

void PT(int Y1){
    //Play Despacito
    while (Y1==HIGH){
      notars(negra, NOTE_D5);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra, NOTE_CS5);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 2, NOTE_B4);
      notars(negra / 4, NOTE_FS4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      delay(negra / 4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 4, NOTE_FS4);
      notars(negra / 4, NOTE_FS4);
      notars(negra / 4, NOTE_FS4);
      notars(negra / 4, NOTE_FS4);
      notars(negra / 4, NOTE_FS4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 4, NOTE_B4);
      notars(negra / 4, NOTE_B4);
      notars(negra / 4, NOTE_B4);
      notars(negra / 2, NOTE_B4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
  
      notars(negra / 4, NOTE_A4);
  
      notars(negra / 4, NOTE_B4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      delay(negra / 4);
      delay(negra / 4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 4, NOTE_G4);
      delay(negra / 4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 4, NOTE_G4);
      notars(negra / 4, NOTE_G4);
      notars(negra / 4, NOTE_G4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 4, NOTE_G4);
      notars(negra / 4, NOTE_G4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 4, NOTE_B4);
      notars(negra / 4, NOTE_B4);
      notars(negra / 4, NOTE_B4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 2, NOTE_B4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
  
      notars(negra / 4, NOTE_CS5);
      notars(negra / 4, NOTE_D5);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      delay(negra / 4);
      delay(negra / 4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 4, NOTE_A4);
      delay(negra / 4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 4, NOTE_A4);
      notars(negra / 4, NOTE_A4);
      notars(negra / 4, NOTE_A4);
      notars(negra / 4, NOTE_A4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 4, NOTE_D5);
      notars(negra / 4, NOTE_CS5);
      notars(negra / 4, NOTE_D5);
      notars(negra / 4, NOTE_CS5);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      notars(negra / 2, NOTE_D5);
      notars(negra / 4, NOTE_E5);
      notars_jai(negra / 2, NOTE_E5, negra / 4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      //-----------------------------------------------
      tone(3, NOTE_CS5 , negra * 3 / 4);
      //-----------------------------------------------
      delay(negra / 4);
      delay(negra / 4);
      delay(negra / 4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      noTone(3);
      delay(negra / 4);
      delay(negra / 4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
      delay(negra / 4);
      delay(negra / 4);
      Y1 = digitalRead(button1);
      if (Y1 != HIGH) {
        break;
      }
    }
}

void notars(int noteDuration, int LaNota ) {
  tone(6, LaNota , noteDuration * 0.9);
  pauseBetweenNotes = noteDuration * 1.1;
  delay(pauseBetweenNotes);
  noTone(6);
}
void notars_jai(int noteDuration, int LaNota , int Desfase) {
  tone(6, LaNota , noteDuration * 0.9);
  pauseBetweenNotes = noteDuration * 1.1;
  delay(Desfase);
  delay(pauseBetweenNotes - Desfase);
  noTone(6);
}

void marioplay(int button){
int speakerpin = 6;
pinMode(6,OUTPUT);


// notes in the melody:
int Mario_melody[] = {
  NOTE_E4, NOTE_E4, REST, NOTE_E4, 
  REST, NOTE_C4, NOTE_E4, REST,
  NOTE_G4, REST, REST, NOTE_G3, REST,
  
  NOTE_C4, REST, REST, NOTE_G3,
  REST, NOTE_E3, REST,
  REST, NOTE_A3, REST, NOTE_B3,   
  REST, NOTE_AS3, NOTE_A3, REST,
  
  NOTE_G3, NOTE_E4, NOTE_G4,
  NOTE_A4, REST, NOTE_F4, NOTE_G4, 
  REST, NOTE_E4, REST, NOTE_C4, 
  NOTE_D4, NOTE_B3, REST
};

int Mario_Notes[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 2, 4, 2, 2,
  
  4, 4, 4, 4,
  2, 4, 4,
  4, 4, 4, 4,  
  4, 4, 4, 4,
  
  4, 2, 4,
  4, 4, 4, 4,
  4, 4, 4, 4, 
  4, 4, 2
  };
  
  int num_elements_in_arr = sizeof(Mario_Notes)/sizeof(Mario_Notes[0]);
  for (int thisNote = 0; thisNote < num_elements_in_arr && digitalRead(13)==HIGH; thisNote++) {
     Serial.println("loop works");
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 500/Mario_Notes[thisNote];
    tone(speakerpin, Mario_melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerpin);
  }
}
void setTone(int pin, int note, int duration) {
  tone(pin, note, duration);
  delay(duration);
  noTone(pin);
}

void playTune(char note, int duration) {
  int buzzerPin = 6;
  char notesName[] = { 'c', 'd', 'e', 'f', 'g' };
  int tones[] = { 261, 293, 329, 349, 392 };

  for (int i = 0; i < sizeof(tones); i++) {
    // Bind the note took from the char array to the array notesName
    if (note == notesName[i]) {
      // Bind the notesName to tones
      tone(buzzerPin, tones[i], duration);
    }
  }
}

void jinglebells(int button){
int buzzerPin = 6;
int tempo = 200;
char notes[] = "eeeeeeegcde fffffeeeeddedg";
int duration[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

  
  // Scan each char from "notes"
  for (int i = 0; i < sizeof(notes)-1 && digitalRead(button)==HIGH; i++) {

    if (notes[i] == ' ') {
      // If find a space it rests
      delay(duration[i] * tempo);
    } else {
      playTune(notes[i], duration[i] * tempo);
    }

    // Pauses between notes
    delay((tempo*2)*duration[i]);
  }

}
 void harrypotter(int button){
int led_pin = 13;
int buzzer_pin = 6;

struct MusicStruct {
  int A = 550;
  int As = 582;
  int B = 617;
  int C = 654;
  int Cs = 693;
  int D = 734;
  int Ds = 777;
  int E = 824;
  int F = 873;
  int Fs = 925;
  int G = 980;
  int Gs = 1003;
  int A2 = 1100;
  int A2s = 1165;
  int B2 = 1234;
  int C3 = 1308;
  int C3s = 1385;
  int D3 = 1555;
}Music;

struct LengthStruct {
  float half = 0.5;
  float one = 1.0;
  float one_half = 1.5;
  float two = 2.0;
  float two_half = 2.5;
}Length;

int tempo = 400;


  pinMode(led_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);





while(digitalRead(button)==HIGH){
  Serial.println("Running");
  if (!digitalRead(button)==HIGH){
    break;
    }
  setTone(buzzer_pin, Music.B, tempo * Length.one);
    if (!digitalRead(button)==HIGH){
    break;
    }
    
  setTone(buzzer_pin, Music.E, tempo * Length.one_half);
    if (!digitalRead(button)==HIGH){
    break;
    }
  setTone(buzzer_pin, Music.G, tempo * Length.half);
    if (!digitalRead(button)==HIGH){
    break;
    }
  setTone(buzzer_pin, Music.F, tempo * Length.one);
    if (!digitalRead(button)==HIGH){
    break;
    }
  setTone(buzzer_pin, Music.E, tempo * Length.two);
    if (!digitalRead(button)==HIGH){
    break;
    }
  setTone(buzzer_pin, Music.B2, tempo * Length.one);
    if (!digitalRead(button)==HIGH){
    break;
    }
  setTone(buzzer_pin, Music.A2, tempo * Length.two_half);
  setTone(buzzer_pin, Music.Fs, tempo * Length.two_half);
    if (!digitalRead(button)==HIGH){
    break;
    }
  setTone(buzzer_pin, Music.E, tempo * Length.one_half);
  setTone(buzzer_pin, Music.G, tempo * Length.half);
    if (!digitalRead(button)==HIGH){
    break;
    }
  setTone(buzzer_pin, Music.F, tempo * Length.one);
  setTone(buzzer_pin, Music.Ds, tempo * Length.two);
    if (!digitalRead(button)==HIGH){
    break;
    }
  setTone(buzzer_pin, Music.F, tempo * Length.one);
  setTone(buzzer_pin, Music.B, tempo * Length.two_half);
    if (!digitalRead(button)==HIGH){
    break;
    }
//  delay(500000);
}

}
