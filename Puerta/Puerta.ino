

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define echoPin 8
#define trigPin 9
long duration1, distance1;


SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  myDFPlayer.begin(mySoftwareSerial),
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  
}

void loop()
{
 
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
   delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration1 = pulseIn(echoPin, HIGH);
    distance1 = (duration1/2) / 29.1;
  
  if (distance1<=40)

  {
    myDFPlayer.play(1);  //Play next mp3 every 3 second.
    delay(1000);
  }
  
}

  
