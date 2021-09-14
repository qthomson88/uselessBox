//sketch for my useless box

//need a function to turn off the switch when the switch is moved to the on position

//need a function to play music/flash lights or do something to taunt a person as they walk by (probably going to be a light sensor)
//I'm thinking music. I want it to play for at least five seconds, but longer if they keep standing in front of the box without opening it

//play different music when box is opened - another light sensor

//***************
//adventure mode*
//***************
//once the switch is pushed there is a time limit to push it back or lose a heart
//three hearts and you lose (possibly cue death music)

//push the switch back within the allotted time and the box loses a life point
//successfully push the switch three times and you win (possibly cue victory music)

//*************
//master quest*
//*************
//similar to adventure mode, but the time before the box pushes the switch varies randomly
//maybe a shorter time to push the switch back
//maybe have the arm come out part way before pushing the switch back to further taunt the player

//optional upgrade: make the box move around in response to player's attempts to push button

//optional upgrade: shoot something at the player randomly or in respnse to failure to push the switch back in time

#include <Servo.h>

#define REST    0

#define QUARTER 4
#define HALF    2
#define WHOLE   1
#define TRIPLET 12
#define TWO_COUNT_TRIPLET 6

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Mario main theme melody
//int melody[] = {
//  NOTE_E7, QUARTER,
//  NOTE_E7, QUARTER,
//  REST, QUARTER,
//  NOTE_E7, QUARTER,
//  
//  REST, QUARTER,
//  NOTE_C7, QUARTER,
//  NOTE_E7, QUARTER,
//  REST, QUARTER,
//  
//  NOTE_G7, QUARTER,
//  REST, QUARTER,
//  REST, HALF,
//  
//  NOTE_G6, QUARTER,
//  REST, QUARTER,
//  REST, HALF,
//  
//  NOTE_C7, QUARTER,
//  REST, QUARTER,
//  REST, QUARTER,
//  NOTE_G6, QUARTER,
//  
//  REST, HALF,
//  NOTE_E6, QUARTER,
//  REST, QUARTER,
//  
//  REST, QUARTER,
//  NOTE_A6, QUARTER,
//  REST, QUARTER,
//  NOTE_B6, QUARTER,
//  
//  REST, QUARTER,
//  NOTE_AS6, QUARTER,
//  NOTE_A6, QUARTER, 
//  REST, QUARTER,
//  
//  NOTE_G6, TWO_COUNT_TRIPLET,
//  NOTE_E7, TWO_COUNT_TRIPLET,
//  NOTE_G7, TWO_COUNT_TRIPLET,
//  
//  NOTE_A7, QUARTER,
//  REST, QUARTER,
//  NOTE_F7, QUARTER,
//  NOTE_G7, QUARTER,
//  
//  REST, QUARTER,
//  NOTE_E7, QUARTER,
//  REST, QUARTER,
//  NOTE_C7, QUARTER,
//  
//  NOTE_D7, QUARTER,
//  NOTE_B6, QUARTER,
//  REST, HALF,
//
//  NOTE_C7, QUARTER,
//  REST, QUARTER,
//  REST, QUARTER,
//  NOTE_G6, QUARTER,
//  
//  REST, HALF,
//  NOTE_E6, QUARTER,
//  REST, QUARTER,
//  
//  REST, QUARTER,
//  NOTE_A6, QUARTER,
//  REST, QUARTER,
//  NOTE_B6, QUARTER,
//  
//  REST, QUARTER,
//  NOTE_AS6, QUARTER,
//  NOTE_A6, QUARTER,
//  REST, QUARTER,
//
//  NOTE_G6, TWO_COUNT_TRIPLET,
//  NOTE_E7, TWO_COUNT_TRIPLET,
//  NOTE_G7, TWO_COUNT_TRIPLET,
//  
//  NOTE_A7, QUARTER,
//  REST, QUARTER,
//  NOTE_F7, QUARTER,
//  NOTE_G7, QUARTER,
//  
//  REST, QUARTER,
//  NOTE_E7, QUARTER,
//  REST, QUARTER,
//  NOTE_C7, QUARTER,
//  
//  NOTE_D7, QUARTER,
//  NOTE_B6, QUARTER,
//  REST, HALF
//};

//Underworld melody
//int underworld_melody[] = {
//  NOTE_C4, QUARTER,
//  NOTE_C5, QUARTER,
//  NOTE_A3, QUARTER,
//  NOTE_A4, QUARTER,
//  
//  NOTE_AS3, QUARTER,
//  NOTE_AS4, QUARTER,
//  REST, HALF,
//  
//  REST, WHOLE,
//  
//  NOTE_C4, QUARTER,
//  NOTE_C5, QUARTER,
//  NOTE_A3, QUARTER,
//  NOTE_A4, QUARTER,
//  
//  NOTE_AS3, QUARTER,
//  NOTE_AS4, QUARTER,
//  REST, HALF,
//  
//  REST, WHOLE,
//  
//  NOTE_F3, QUARTER,
//  NOTE_F4, QUARTER,
//  NOTE_D3, QUARTER,
//  NOTE_D4, QUARTER,
//  
//  NOTE_DS3, QUARTER,
//  NOTE_DS4, QUARTER,
//  REST, HALF,
//  
//  REST, WHOLE,
//  
//  NOTE_F3, QUARTER,
//  NOTE_F4, QUARTER,
//  NOTE_D3, QUARTER,
//  NOTE_D4, QUARTER,
//  
//  NOTE_DS3, QUARTER,
//  NOTE_DS4, QUARTER,
//  REST, HALF,
//  
//  REST, HALF,
//  NOTE_DS4, TRIPLET,
//  NOTE_CS4, TRIPLET,
//  NOTE_D4, TRIPLET,
//  
//  NOTE_CS4, HALF,
//  NOTE_DS4, HALF,
//  
//  NOTE_DS4, HALF,
//  NOTE_GS3, HALF,
//  
//  NOTE_G3, HALF,
//  NOTE_CS4, HALF,
//  
//  NOTE_C4, TRIPLET,
//  NOTE_FS4, TRIPLET,
//  NOTE_F4, TRIPLET,
//  
//  NOTE_E3, TRIPLET,
//  NOTE_AS4, TRIPLET,
//  NOTE_A4, TRIPLET,
//  
//  NOTE_GS4, TWO_COUNT_TRIPLET,
//  NOTE_DS4, TWO_COUNT_TRIPLET,
//  NOTE_B3, TWO_COUNT_TRIPLET,
//  
//  NOTE_AS3, TWO_COUNT_TRIPLET,
//  NOTE_A3, TWO_COUNT_TRIPLET,
//  NOTE_GS3, TWO_COUNT_TRIPLET,
//  
//  REST, WHOLE,
//  
//  REST, WHOLE,
//  
//  REST, WHOLE
//};

  int beatsPerMinute = 200;
  int beatsPerSecond = beatsPerMinute/60;
  int beatsPerMeasure = 2;
  int secondsPerMeasure = (beatsPerSecond * beatsPerMeasure) / 1000;

//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

  Servo myservo;  // create servo object to control a servo
 
  
  //**********
  //constants*
  //**********
  #define TAUNT_DARK_LEVEL 511
  
  //*****************
  //pin assignments*
  //*****************
  int buttonApin = 8;
  int lightPinTaunt = 0;
  int lightPinOpen = 1;
  int melodyPin = 3;
  
  //*****************
  //variables*
  //*****************
  int lightReadingTaunt;
  int lightReadingBoxOpen;
  int servoPos;    // variable to store the servo position
  bool startTauntMusic;
  int currNote;
  int tauntMusicCountDown;



void setup() 
{
  // put your setup code here, to run once:
  
  //************
  //setup pins*
  //************
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(melodyPin, OUTPUT);//buzzer 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
  
  //*********************
  //initialize variables*
  //*********************
  servoPos = 0;
  currNote = 0;
  tauntMusicCountDown = 5;
}

void loop() 
{
  //when the photocell detects dark, presumed to be someone walking by, taunt them
  lightReadingTaunt  = analogRead(lightPinTaunt);
  
  if(lightReadingTaunt <= TAUNT_DARK_LEVEL)
  {
    startTauntMusic = true;
    tauntMusicCountDown = 5;
    currNote = 0;
        for (servoPos = 0; servoPos <= 90; servoPos += 5) 
    { 
      myservo.write(servoPos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (servoPos = 90; servoPos >= 0; servoPos -= 5) 
    {
      myservo.write(servoPos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
  
  //want the taunt music to play at least the intro, but keep playing if the person is still standing in front of the light sensor
  while(lightReadingTaunt <= TAUNT_DARK_LEVEL || startTauntMusic)
//  {
//    if(startTauntMusic)
//    {
//          //move the servo
//
////      buzz(melodyPin, melody[currNote], secondsPerMeasure/melody[currNote + 1]);
//      // to distinguish the notes, set a minimum time between them.
//      // the note's duration + 30% seems to work well:
////      int pauseBetweenNotes = (secondsPerMeasure/melody[currNote + 1]) * 1.30;
////      delay(pauseBetweenNotes);
//
//      int noteDuration = 1000 / tempo[currNote];
//
//      buzz(melodyPin, melody[currNote], noteDuration);
//      
//      // to distinguish the notes, set a minimum time between them.
//      // the note's duration + 30% seems to work well:
//      int pauseBetweenNotes = noteDuration * 1.30;
//      delay(pauseBetweenNotes);
//
//      // stop the tone playing:
//      buzz(melodyPin, 0, secondsPerMeasure/melody[currNote + 1]);
//      tauntMusicCountDown -= 1;
//      currNote += 1;
//      
//      if(tauntMusicCountDown >= 0)
//      {
//        startTauntMusic = false; 
//      }
//      
//      //if the box is open break out
//    }
//    
//    else
//    {
//      buzz(melodyPin, melody[currNote], melody[currNote + 1]);
//      currNote += 1;
//      //if the box is open break out
//    }
//  }


  //this is the main function of the useless box - move the servo and push the switch back to off
  if (digitalRead(buttonApin) == LOW)
  {
    //move the servo
    for (servoPos = 0; servoPos <= 90; servoPos += 5) 
    { 
      myservo.write(servoPos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (servoPos = 90; servoPos >= 0; servoPos -= 5) 
    {
      myservo.write(servoPos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }

}

void buzz(int targetPin, long frequency, long length) 
{
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) 
  { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
}
