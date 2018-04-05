/*

 * codeexample for useing a 4051 * analog multiplexer / demultiplexer

 * by david c. and tomek n.* for k3 / malm� h�gskola

 *

 * edited by Ross R.

 * edited by Igor de Oliveira Sá.

 */  

 

int r0 = 0;      //value of select pin at the 4051 (s0)

int r1 = 0;      //value of select pin at the 4051 (s1)

int r2 = 0;      //value of select pin at the 4051 (s2)

 

int s0 = 2;

int s1 = 3;

int s2 = 4;

int count = 0;   //which y pin we are selecting

 

void setup(){  

  pinMode(s0, OUTPUT);

  pinMode(s1, OUTPUT);

  pinMode(s2, OUTPUT);

  Serial.begin(9600);

}

 

void loop () {

 

  for (count=0; count<=2; count++) {

 

    // select the bit  

    r0 = bitRead(count,0);    // use this with arduino 0013 (and newer versions)     

    r1 = bitRead(count,1);    // use this with arduino 0013 (and newer versions)     

    r2 = bitRead(count,2);    // use this with arduino 0013 (and newer versions)     

 

    digitalWrite(s0, r0);

    digitalWrite(s1, r1);

    digitalWrite(s2, r2);

 

    //Either read or write the multiplexed pin here
   digitalWrite(A0, HIGH);

   delay(1000);
 

  }  

}

