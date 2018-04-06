// Define the LED digit patters, from 0 - 9
// Note that these patterns are for common cathode displays
// For common anode displays, change the 1's to 0's and 0's to 1's
// 1 = LED on, 0 = LED off, in this order:
//{1,2,3,4,5,6,7}
byte seven_seg_digits[12][9] = { 
  { 1,1,1,1,1,1,0,1},  // = 0 
  { 1,1,1,0,0,0,0,0},  // = 1
  {1,0,1,1,1,1,1,0},  // = 2
  {1,1,1,1,1,0,1,0},  // = 3
  {1,1,1,0,0,0,1,1},  // = 4
  {1,1,0,1,1,0,1,1},  // = 5
  {1,1,0,1,1,1,1,1},  // = 6
  {1,1,1,1,0,0,0,0},  // = 7
  {1,1,1,1,1,1,1,1},  // = 8
  {1,1,1,1,1,0,1,1},   // = 9
  {0,0,0,0,0,0,1,0}, // = dash
  {0,0,0,0,0,0,0,0},//all off
                        };
int startpoint =2;//if you would like to remove the dot change this number to 3 (dot pin is connected to pin 3)
//int dotPin = 3;

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

//PIN NUMBERS
//    ---6---
  // -       -
  // 10      5
  // -       -
  // - --9-- -
  // -       -
  // 8       4
  // -       -
  // -       -
  //  ---7--      .3

void setup() {                
  startPoint(startpoint);//3
  Serial.begin(9600);      
}



void loop() {
  {
    //415-551-9248
   delay(1000);
   sevenSegWrite(4);
   delay(1000); 
   sevenSegWrite(1);
   delay(1000); 
   sevenSegWrite(5); 
   delay(1000);
   sevenSegWrite(10);   // dash 
   delay(1000);
   sevenSegWrite(5);
   delay(1000);
   sevenSegWrite(11);//off
   delay(500); 
   sevenSegWrite(5);
   delay(1000); 
   sevenSegWrite(1);
   delay(1000);
   sevenSegWrite(10);   // dash 
   delay(1000); 
   sevenSegWrite(9); 
   delay(1000);
   sevenSegWrite(2); 
   delay(1000);
   sevenSegWrite(4);
   delay(1000); 
   sevenSegWrite(8);
   delay(1000); 
  }
  delay(4000);

  for (byte count = 10; count > 0; --count) {
   delay(100);
   sevenSegWrite(count - 1); 
  }

  // alert
  //alert(50);
  //delay(4000);
}


//void writeDot(byte dot, int dotPin) {
  //digitalWrite(dotPin, dot);
//}
    
void startPoint(int start){//change 10 to 9 if you removed dot pin above
for (int i = 0; i < 10; ++i)
{
  /* code */
  pinMode(start+i,OUTPUT);//turns on all pins as output mode
}
//writeDot(0, start + 1);
}
void sevenSegWrite(byte digit) {
  byte pin = startpoint +1;
  Serial.println(digit,DEC);//prints the number in the array would be off if another number sequence      
  for (byte segCount = 0; segCount < 8; ++segCount) {
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
