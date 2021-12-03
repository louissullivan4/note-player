/* Tone Generation - Program that reads in characters from the serial monitor running on the PC and 
 * play the corresponding note. Use the space character to represents a period of silence. Any 
 * character, received from the serial monitor, not in the set {A,B,C,D,E,F,G, space} should be ignored.
 * 
 * Louis Sullivan 21/09/2021
 */

//Output Pin
#define ledoutput 13
//List of notes and their frequencies 
#define mid_C 3787
#define D 3405
#define E 3033
#define G 2551
#define A 2272
#define B 2145
#define C 955
//notes added to list
short notes [] = {D,E,G,A,B,C};
//frequencies added to list
short freq [] = {3405,3033,2551,2272,2145,955};

//Note take in
void playnote(int note){
   int song = 100;
   //while we are playing the note
     while (song--){
        digitalWrite(ledoutput, HIGH);   
        delayMicroseconds((notes[note]) / 2);
        digitalWrite(ledoutput, LOW);  
        delayMicroseconds((notes[note]) / 2);
   }
}

void setup() {
  //open serial monitor
  Serial.begin(9600);  
  pinMode(ledoutput, OUTPUT);
}

void loop() {
  char NoteIn;
  if (Serial.available()) {
    //take note in from serial montior
    NoteIn = Serial.read();
    //if note is chosen play appropiate frequency
    switch (NoteIn){
      case 'd' : playnote(0); break;
      case 'e' : playnote(1); break;
      case 'g' : playnote(2); break;
      case 'a' : playnote(3); break;
      case 'b' : playnote(4); break;
      case 'c' : playnote(5); break;
      case ' ' : delay(10);
    }
  }  
}
