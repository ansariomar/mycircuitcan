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

code uses microseconds because milliseconds are too long for it to operate properly

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


