#include <Tone.h>
Tone tone1;
float distance, duration;
//array of notes that can be played 
int notes[] = { NOTE_C4,
                NOTE_D4,
                NOTE_E4,
                NOTE_F4,
                NOTE_G4,
                NOTE_A3,
                NOTE_B3};
                
char values [] = {'C','D','E','F','G','A','B','N'};
int trig[]={41,43,45,47,49,51,53};
int echo[]={40,42,44,46,48,50,52};
//trig pin for ultrasonic sensors {41 - 53}
//echo pin for ultrasonic sensors {40 - 52}

//buzzer on Pin 9
const int buzzer =9;
void setup() {
pinMode(buzzer,OUTPUT);
  for (int i=0; i<7; i+=1){
  pinMode(trig[i],OUTPUT);
  pinMode(echo[i],INPUT);
  }
  tone1.begin(9);
Serial.begin(9600);

}

void loop() {
  for (int i=0; i<7; i+=1){
  digitalWrite(trig[i],LOW);
  delayMicroseconds(2);
  digitalWrite(trig[i],HIGH);
  delayMicroseconds(2);
  digitalWrite(trig[i],LOW);

  long duration = pulseIn(echo[i],HIGH);
  int distance = 0.0343 * (duration/2);
  Serial.print("Distance");
  Serial.print(i+1);
  Serial.print(" : ");

  Serial.print(distance);
  Serial.print(" ");
  delayMicroseconds(5);
    if (distance <15 && distance > 0){
      Serial.println("Sensor");
      Serial.print(i+1);
      Serial.print(" will play");
      Serial.print(values[i]);
      playTone(values[i]);
    }
    else {
      playTone(values[7]);
    }

  }

  Serial.println("");
}
  


void playTone (char values){
switch (values){
  case 'C':
  Serial.println("C");
  tone1.play(notes[0]);
  break;
  
  case 'D':
  Serial.println("D");
  tone1.play(notes[1]);
  
  break;
  
  case 'E':
  Serial.println("E");
  tone1.play(notes[2]);
  
  break;
  
  case 'F':
  Serial.println("F");
  tone1.play(notes[3]);
  
  break;
  
  case 'G':
  Serial.println("G");
  tone1.play(notes[4]);
  
  break;
  
  case 'A':
  Serial.println("A");
  tone1.play(notes[5]);
  
  break;
  
  case 'B':
  Serial.println("B");
  tone1.play(notes[6]);
  break;

  case 'N':
  Serial.println("N");
  tone1.stop();
  

  }
}
