
//Hand wired LED matrix

#define Speed 500 //frame rateish


// 2-dimensional array of row pin numbers:
const int col[8] = {
  0, 1, 2, 3, 4, 5, 6, 7
};

// 2-dimensional array of column pin numbers:
const int row[8] = {
  8, 9, 10, 11, 12, 13, 14, 15
};

// 2-dimensional array of pixels:
int pixels[8][8];

int count = Speed;

int ptrChar = 0;


typedef bool charMapType[8][8];

const charMapType charBlank = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType frame0 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 1, 1, 1, 0, 1, 0, 0},
  {0, 1, 0, 1, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType frame1 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 1, 0, 1, 0},
  {0, 0, 1, 1, 1, 0, 1, 0},
  {1, 0, 1, 0, 1, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType frame2 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 1, 0, 1, 0, 1},
  {1, 0, 0, 1, 1, 1, 0, 1},
  {1, 1, 0, 1, 0, 1, 0, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType frame3 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 1, 0, 0, 1, 1, 1, 0},
  {0, 1, 1, 0, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType frame4 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 1, 1, 1},
  {1, 0, 1, 1, 0, 1, 0, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType frame5 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 1, 0},
  {1, 1, 0, 1, 0, 0, 1, 1},
  {0, 1, 0, 1, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType frame6 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 1, 0, 1, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType *charMap[7] = {&frame0, &frame1, &frame2, &frame3, &frame4, &frame5, &frame6};//change this if you add more frames

void setup() {
  // initialize the I/O pins as outputs
  // iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the row pins (i.e. the cathodes) high to ensure that
    // the LEDS are off:
    digitalWrite(row[thisPin], HIGH);
  }

  //setupScreen();
  setupChar();

}

void loop() {

  // draw the screen:
  refreshScreen();
  
  if(count-- == 0){
    count = Speed;
    setupChar();
  }

}

void setupChar(){
  
  const charMapType *cMap = charMap[ptrChar];
  //charMapType *cMap = &charDummy;
  
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      bool v = (*cMap)[x][y];
      
      if(v){
        pixels[x][y] = LOW;
      }else{
        pixels[x][y] = HIGH;
      }
    }
  }
  
  ptrChar++;
  if(ptrChar>=7){//change the number value if you add frames
    ptrChar = 0;
  }

}

void refreshScreen() {
  // iterate over the cols (anodes):
  for (int thisCol = 0; thisCol < 8; thisCol++) {
    // take the col pin (anode) high:
    digitalWrite(col[thisCol], HIGH);
    // iterate over the rows (cathodes):
    for (int thisRow = 0; thisRow < 8; thisRow++) {
      // get the state of the current pixel;
      int thisPixel = pixels[thisRow][thisCol];
      // when the col is HIGH and the row is LOW,
      // the LED where they meet turns on:
      digitalWrite(row[thisRow], thisPixel);
      // turn the pixel off:
      if (thisPixel == LOW) {
        digitalWrite(row[thisRow], HIGH);
      }
    }
    // take the col pin low to turn off the whole row:
    digitalWrite(col[thisCol], LOW);
  }
}
