// Define the LED digit patters, from 0 - 9
// Note that these patterns are for common cathode displays
// For common anode displays, change the 1's to 0's and 0's to 1's
// 1 = LED on, 0 = LED off, in this order:
byte seven_seg_digits[10][7] = { {1,1,1,1,1,0,1 },  // = 0 {1,2,3,4,5,6,7}
                                                           {1,1,0,0,0,0,0 },  // = 1
                                                           {0,1,1,1,1,1,0 },  // = 2
                                                           {1,1,1,1,0,1,0 },  // = 3
                                                           {1,1,0,0,0,1,1 },  // = 4
                                                           {1,0,1,1,0,1,1 },  // = 5
                                                           {1,0,1,1,1,1,1 },  // = 6
                                                           {1,1,1,0,0,0,0 },  // = 7
                                                           {1,1,1,1,1,1,1 },  // = 8
                                                           {1,1,1,1,0,1,1 }   // = 9
                                                           };
int startpoint =3;


  //  ---3---
  // -       -
  // 7       2
  // -       -
  // - --6-- -
  // -       -
  // 5       1
  // -       -
  // -       -
  //  ---4--      .0



void setup() {                
  // pinMode(2, OUTPUT);   
  // pinMode(3, OUTPUT);
  // pinMode(4, OUTPUT);
  // pinMode(5, OUTPUT);
  // pinMode(6, OUTPUT);
  // pinMode(7, OUTPUT);
  // pinMode(8, OUTPUT);
  // pinMode(9, OUTPUT);
  startPoint(startpoint);
  Serial.begin(9600);      
}



void loop() {
  for (byte count = 10; count > 0; --count) {
   delay(1000);
   sevenSegWrite(count - 1); 
  }
  delay(4000);

  for (byte count = 10; count > 0; --count) {
   delay(100);
   sevenSegWrite(count - 1); 
  }

  // alert
  alert(50);
  delay(4000);
}


void writeDot(byte dot, int dotPin) {
  digitalWrite(dotPin, dot);
}
    
void startPoint(int start){
for (int i = 0; i < 8; ++i)
{
  /* code */
  pinMode(start+i,OUTPUT);
}
writeDot(0, start + 1);
}
void sevenSegWrite(byte digit) {
  byte pin = startpoint +1;
  Serial.println(digit,DEC);      
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void alert(int time){
  // byte alert_digits[7] = { 0,0,0,0,0,0,0 };
  int pin = startpoint +1;
  for (int i = 0; i < 4; ++i)
  {
    /* code */
pin = startpoint +1;
for (int segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, 0);
    ++pin;
  }
  pin = startpoint +1;
  delay(time);
  for (int segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, 1);
    ++pin;
  }
  delay(time);
    }

}
