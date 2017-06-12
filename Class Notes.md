Class Notes 5/26
  
H-Bridge: 
  
(Texas Instruments L293NE) 
  
is made up of 16 pins and is counted in a 'U' shape (1 is directly across from 16).  
  
Operates between 4.5V and 36V.
  
Uses two pins on either side (4,5 and 12,14) as a heatsink to ensure cooling/protection from over heating
  
Can be used to power two motors 
  
____________________________

Class Notes 5/31

  
``` 
const int sensorPin = A0;    // select the input pin for the potentiometer
const int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
```

is beter than

``` 
const int sensorPin = A0;    // select the input pin for the potentiometer
const int ledPin = 13;      // select the pin for the LED
const int sensorValue = 0;  // variable to store the value coming from the sensor
```

because if all values are constant the action based on a variable will not be possible (const int vs int)

using // is often used as a way of "commenting out" a portion of code so that it is still visable to the programmer but not read as code

Using additional power (9v or 6v batt pack) source when powering multiple outputs helps to prevent system shutdown caused by fluctuation in power when load is too high.

Circuit was unable to reverse direction of motor due to faulty wire at digital pin 4.  Sketch performed as expected once wire was changed.
__________________________________________________________________________________________________________________________________________
  
Class Notes 6/2

Testing motor without H-bridge

Testing H-bridge without Arduino

Testing program without H-bridge

2 types of voltage AC (alternating current) and DC (direct current)

How test a multimeter: place black wire in grnd on breadboard and red wire into 5V= should read between 4.75-5.25V

/* until /* is all treated as comment whereas // is only treated as a comment for the line it is written on

Distance Measuring Sensor

VCC: to Arduino 5V GND: to Arduino GND Trig: Emits sonic pulse for location (output) Echo: Listens/receives pulse completing the loop (input)

code uses microseconds because milliseconds are too 

for it to operate properly

long

Description

Long variables are extended size variables for number storage, and store 32 bits (4 bytes), from -2,147,483,648 to 2,147,483,647.

Functions: Either require no, single, or multiple parameters

when "calling" a function the word "void" is placed in front of it

Servo Motors:

Moves at 180° Signal = Orange 5V= Red GND = Brown

#include <Servo.h>
is needed to use servo motors

then you need to create a "handle" then you use that handle to assign the servo to a particular pin by writing assigned handle name.attach(pin #) example: myservo.attach(9); // attaches the servo to pin 9 to the servo object

______________________________________________________

Class Notes 6/5

A "shield" is a more stable and permanent version of a breadboard.  Contains sockets and pins

"Feed through headers" same as "stacking headers"

Male headers plug into female headers

Creating a "function"

by relocating a sequence of code into the end of a program under the loop

examples:

```
void stop () {
```
or

```
long getDistance(){
```
code can be treated as a function so that you simply write stop or getDistance, or any other action you want to perform without having to write the code repeatedly

"-1" is used to indicate an error 

Light Seeking Robot:

```
int rightSensor=analogRead (rightSensorPin);
int leftSenson=analogRead (rightSensorPin);

if (rightSensor>leftSensor) {
turnRight ();
} else{
turnLeft();
```
}
______________________________

Class Notes 6/9

Both "int" and "long" cannot recognize numbers after a decimal. "Float" allows storage and recognition of decimal points in code.

Arrays need to contain a description of the number of intergers being placed within them.

"Boolean" is used to describe true or false statements

```
const int led1Pin = 9;
const int led2Pin = 4;



const int led10Pin = 7;
const int ledPins [] = {9, 4, 7, 2, 3, 5, 6, 8, 12, 11};

//or
//const int ledPins[10];

void setup () {


  for (int i = 0; i < 10; i = i + 1) {
    pinMode(ledPins[i], OUTPUT);
    Serial.begin(9600);
    Serial.println(ledPins[i]);
    delay(1000);



  }
}


void loop () {

}
````

Class contains objects

"Serial" is a type of object that exists inside of the class "Print"

"Constructor" is the name for the initializer of a "Class"

___________________________________________________________

Class Notes 6/12

Using a potentiometer to help match motor speeds 

```
/*
Simple light seeking robot with Mega Motor motor controller
*/


// Pin usage

// Mega Motor shield
const int MegaMotorEnable = 12;
const int MegaMotorPWMLeft = 6; // PWMA from pin D6 – Timer0 PWM0A
const int MegaMotorPWMRight = 5; // PWMB from pin D5 – Timer0 PWM0B

// Light sensors
const int leftSensor = A0;
const int rightSensor = A1;

// Adjustment potentiometer
const int adjustPin = A2;


void setup()
{
  pinMode(MegaMotorEnable, OUTPUT);
  pinMode(MegaMotorPWMLeft, OUTPUT);
  pinMode(MegaMotorPWMRight, OUTPUT);
  Serial.begin(9600);
}

void loop() // run over and over
{
  int leftLightLevel = analogRead(leftSensor);
  int rightLightLevel = analogRead(rightSensor);
  int adjust = analogRead(adjustPin);

  adjust = adjust - 512;

  rightLightLevel = rightLightLevel - adjust;

  debugPrinting(leftLightLevel, rightLightLevel);

  if ( leftLightLevel > rightLightLevel) {
    Serial.print(" turning right");
    turnRight(100);
  } else {
    Serial.print(" turning left");
    turnLeft(100);
  }
  Serial.println();
}

void   debugPrinting(int left, int right) {
  Serial.print("left level = ");
  Serial.print(left);
  Serial.print("\tright level = ");
  Serial.print(right);
}

void goForward(int moveTime) {
  digitalWrite(MegaMotorEnable, HIGH);
  digitalWrite(MegaMotorPWMLeft, HIGH);
  digitalWrite(MegaMotorPWMRight, HIGH);
  delay(moveTime);
}

void turnRight(int moveTime) {
  digitalWrite(MegaMotorEnable, HIGH);
  digitalWrite(MegaMotorPWMLeft, HIGH);
  digitalWrite(MegaMotorPWMRight, LOW);
  delay(moveTime);
}

void turnLeft(int moveTime) {
  digitalWrite(MegaMotorEnable, HIGH);
  digitalWrite(MegaMotorPWMLeft, LOW);
  digitalWrite(MegaMotorPWMRight, HIGH);
  delay(moveTime);
}
void stop() {
  digitalWrite(MegaMotorEnable, LOW);
  digitalWrite(MegaMotorPWMLeft, LOW);
  digitalWrite(MegaMotorPWMRight, LOW);

}
```
