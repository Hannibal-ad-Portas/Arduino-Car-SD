#define HB_INPUT1_PIN 6
#define HB_INPUT2_PIN 10
#define HB_INPUT3_PIN 5
#define HB_INPUT4_PIN 9
#include <stdio.h>
#include <stdlib.h>


int incomingByte = 0;
char data[4] = {'x','x','x','x',};
int duration = 0;

void setup() {
  Serial.begin(9600);
  pinMode(HB_INPUT1_PIN, OUTPUT);
  digitalWrite(HB_INPUT1_PIN, LOW); // When not sending PWM, we want it low
  pinMode(HB_INPUT2_PIN, OUTPUT);
  digitalWrite(HB_INPUT2_PIN, LOW); // When not sending PWM, we want it low
  pinMode(HB_INPUT3_PIN, OUTPUT);
  digitalWrite(HB_INPUT3_PIN, LOW); // When not sending PWM, we want it low
  pinMode(HB_INPUT4_PIN, OUTPUT);
  digitalWrite(HB_INPUT4_PIN, LOW); // When not sending PWM, we want it low
}


void moveStop (int time) {
  analogWrite(HB_INPUT1_PIN, LOW);
  analogWrite(HB_INPUT2_PIN, LOW);
  analogWrite(HB_INPUT3_PIN, LOW);
  analogWrite(HB_INPUT4_PIN, LOW);
}

void moveRight (int time) {
  analogWrite(HB_INPUT1_PIN, 150);
  analogWrite(HB_INPUT2_PIN, LOW);
  analogWrite(HB_INPUT3_PIN, 150);
  analogWrite(HB_INPUT4_PIN, LOW);
  delay(time);
}

void moveLeft (int time) {
  analogWrite(HB_INPUT1_PIN, LOW);
  analogWrite(HB_INPUT2_PIN, 150);
  analogWrite(HB_INPUT3_PIN, LOW);
  analogWrite(HB_INPUT4_PIN, 150);
  delay(time);
}

void moveBack (int time) {
  analogWrite(HB_INPUT1_PIN, LOW);
  analogWrite(HB_INPUT2_PIN, 150);
  analogWrite(HB_INPUT3_PIN, 150);
  analogWrite(HB_INPUT4_PIN, LOW);
  delay(time);
}

void moveForward (int time) {
  analogWrite(HB_INPUT1_PIN, 150);
  analogWrite(HB_INPUT2_PIN, LOW);
  analogWrite(HB_INPUT3_PIN, LOW);
  analogWrite(HB_INPUT4_PIN, 150);
  delay(time);
}

void loop() {
  if (Serial.available() > 0) {
    for(int i=0;i<3;i++)
       {
             data[i] = Serial.read();
             Serial.print(data[i]);
             Serial.print("\n");
       }
//       data[0] = 'F';
//       data[1] = 1;
//       data[2] = 0;

  duration = 0 + data[1];
  if (data[2] != 'x'){
      duration = (duration * 10) + data[2];
      if (data[3] != 'x'){
         duration = (duration * 10) + data[3];
      }
  }
  duration = duration * 100;
 

    switch (data[0]) {
      case 'F' :
        moveForward(duration);
        break;
      case 'B' :
        moveBack(duration);
        break;
      case 'L' :
        moveLeft(duration);
        break;
      case 'R':
        moveRight(duration);
        break;
      case 'S' :
        moveStop(0);
        break;
      default :
        moveStop(0);
    }
  }
  moveStop(0);
}
