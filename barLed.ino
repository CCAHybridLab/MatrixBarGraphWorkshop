

boolean Direction = true;
int pre_map = 0;

void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);//turn on pins
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(7, LOW);//set to off for start
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}


void loop() {
  int sensorValue = analogRead(A0);
  int mapValue = map(sensorValue,0,1023,0,5);//maps pot value to a value one more than number of LEDs in the Bar
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



}
