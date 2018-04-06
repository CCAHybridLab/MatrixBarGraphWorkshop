/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
boolean Direction = true;
int pre_map = 0;

void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

// the loop function runs over and over again forever
void loop() {
  int sensorValue = analogRead(A0);
  int mapValue = map(sensorValue,0,1023,0,5);
  delay(100);
  if (pre_map < mapValue) {
    Direction = true;
  } else if (pre_map > mapValue) {
    Direction = false;
  }
  if (pre_map != mapValue) {
    pre_map = mapValue;
  }

  if(mapValue == 1 && Direction == true){
    digitalWrite(7, HIGH);
    }else if(mapValue == 2 && Direction == true){
    digitalWrite(8, HIGH);
    }else if(mapValue == 3 && Direction == true){
    digitalWrite(11, HIGH);
    }else if(mapValue == 4 && Direction == true){
    digitalWrite(12, HIGH);
    }else if(mapValue == 1 && Direction == false){
    digitalWrite(7, LOW);
    }else if(mapValue == 2 && Direction == false){
    digitalWrite(8, LOW);
    }else if(mapValue == 3 && Direction == false){
    digitalWrite(11, LOW);
    }else if(mapValue == 4 && Direction == false){
    digitalWrite(12, LOW);
    }

//  if (sensorValue > 0 && sensorValue <= 255 && Direction == true) {
//    digitalWrite(7, HIGH);
//  } else if (sensorValue > 255 && sensorValue <= 510 && Direction == true) {
//    digitalWrite(8, HIGH);
//  } else if (sensorValue > 510 && sensorValue <= 765 && Direction == true) {
//    digitalWrite(11, HIGH);
//  } else if (sensorValue > 765 && sensorValue <= 1023 && Direction == true) {
//    digitalWrite(12, HIGH);
//  } else if (sensorValue > 0 && sensorValue <= 255 && Direction == false) {
//    digitalWrite(7, LOW);
//  }else if (sensorValue > 255 && sensorValue <= 510 && Direction == false) {
//    digitalWrite(8, LOW);
//  } else if (sensorValue > 510 && sensorValue <= 765 && Direction == false) {
//    digitalWrite(11, LOW);
//  } else if (sensorValue > 765 && sensorValue <= 1023 && Direction == false) {
//    digitalWrite(12, LOW);
//  }

}
