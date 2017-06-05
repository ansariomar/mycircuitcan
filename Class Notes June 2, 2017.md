Class Notes

Testing motor without H-bridge

Testing H-bridge without Arduino

Testing program without H-bridge

2 types of voltage AC (alternating current) and DC (direct current)

How test a multimeter: place black wire in grnd on breadboard and red wire into 5V= should read between 4.75-5.25V

/* until /* is all treated as comment whereas // is only treated as a comment for the line it is written on

Distance Measuring Sensor

VCC: to Arduino 5V
GND: to Arduino GND
Trig: Emits sonic pulse for location (output)
Echo: Listens/receives pulse completing the loop (input)

code uses microseconds because milliseconds are too long for it to operate properly

long

Description

Long variables are extended size variables for number storage, and store 32 bits (4 bytes), from -2,147,483,648 to 2,147,483,647.

Functions:
Either require no, single, or multiple parameters 

when "calling" a function the word "void" is placed in front of it

Servo Motors:

Moves at 180°
Signal = Orange
5V= Red
GND = Brown

```
#include <Servo.h>
```
is needed to use servo motors

then you need to create a "handle"
then you use that handle to assign the servo to a particular pin by writing assigned handle name.attach(pin #)
example: myservo.attach(9); // attaches the servo to pin 9 to the servo object




