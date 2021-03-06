
In order to communicate by sound I have added a piezo speaker to my circuit.  

The delay time must be at least 2x the length of duration of tone in order to hear audible pause between multiple tones
lowest accurate tone possible is 31 hz although values are unsigned integers audible from 0 to 65,535
cannot use analogWrite() on pin # 3 & 11 while using the tone function because tone function uses the same built-in timer that analog write uses for pin # 3 & 11

 /*tone needs 2 arguments to work, but can take three
     1) Pin#
     2) Freq - value in hertz
  */ 3) Duration
creating a tone:

```
// simple piezo speaker tone
// speaker is attached to pin A5 and analog ground

int piezoPin = A5;

void setup() {

}//close setup

// delay time must be at least 2x the length of duration of tone in order to hear audible pause between multiple tones
// lowest accurate tone possible is 31 hz although values are unsigned integers audible from 0 to 65,535
// cannot use analogWrite() on pin # 3 & 11 while using the tone function because tone function uses the same built-in timer that analog write uses for pin # 3 & 11

void loop() {

  /*tone needs 2 arguments to work, but can take three
     1) Pin#
     2) Freq - value in hertz
     3) Duration
  */

  //create a tone
  tone(piezoPin, 100, 500);

  delay (1000);

  tone(piezoPin, 31 , 500);

  delay (1000);

}
```

I've added and edited a Morse code decoder sketch to communicate with Arduino.  This is the original sketch:
  
```
unsigned long signal_len,t1,t2;   //time for which button is pressed
int inputPin = 2;                 //input pin for push button
int ledPin = 4;                   //outpu pin for LED
String code = "";                 //string in which one alphabet is stored

void setup()

{
  Serial.begin(9600);
  pinMode(inputPin, INPUT_PULLUP); //internal pullup resistor is used to simplify the circuit
  pinMode(ledPin,OUTPUT);
}

void loop()
{
NextDotDash:
  while (digitalRead(inputPin) == HIGH) {}
  t1 = millis();                            //time at button press
  digitalWrite(ledPin, HIGH);               //LED on while button pressed
  while (digitalRead(inputPin) == LOW) {}
  t2 = millis();                            //time at button release
  digitalWrite(ledPin, LOW);                //LED off on button release
  signal_len = t2 - t1;                     //time for which button is pressed
  if (signal_len > 50)                      //to account for switch debouncing
  {
    code += readio();                       //function to read dot or dash
  }
  while ((millis() - t2) < 500)           //if time between button press greater than 0.5sec, skip loop and go to next alphabet
  {     
    if (digitalRead(inputPin) == LOW)
    {
      goto NextDotDash;
    }
  }
  convertor();                          //function to decipher code into alphabet
}
char readio()
{
  if (signal_len < 600 && signal_len > 50)
  {
    return '.';                        //if button press less than 0.6sec, it is a dot
  }
  else if (signal_len > 600)
  {
    return '-';                        //if button press more than 0.6sec, it is a dash
  }
}
  
 ```

Now I would like the program to recognize when canned phrases have been entered.

Program now recognizes when canned phrases have been input through Morse code key by adding:

```
{
      Serial.println("<Wrong input>");  //if input code doesn't match any letter, error
      Serial.print("here is the word you typed: ");
      Serial.println(myword);
      if (myword == "HI") {
        Serial.println("You really know how to press my buttons!");
      }
      Serial.println("resetting myword");
      myword = ""; // reset myword to a blank string for next word
    }
    //return(char('A' + i));
  }
  
  ```
  

Next step is to move from a response within the "serial monitor" to an action performed by a peripheral i.e. DC motor or piezo speaker playing 8-bit music.


Success!  By adding:

``` 

if (myword == "HI") {
        moveForward (500); // motors powered on and move forward

        stopMotion (500); // motors powered off
        Serial.println("You really know how to press my buttons!"); //reponse provided in serial monitor when the word "HI" is typed in followed by short pulse to indicate end of word
      }
      Serial.println("resetting myword");
      myword = ""; // reset myword to a blank string for next word
    }

```
    
the program now understands that the a word is a command for an action.  Now time to test the limits.

```
// declare variable pushButton and give it a value of "10" (for pin number 10)
int pushButton = 10;


// attaches servo motor
#include <Servo.h>

Servo myservo;

const int rightLDR = A0;    // pin that the sensor is attached to
const int leftLDR = A1;    // pin that the sensor is attached to
int leftSensorValue;
int rightSensorValue;
int difference;

//attaches distance sensor
const int trigPin = 11;
const int echoPin = 12;


void setup() {

  // provides power to DC motors
  analogWrite (6, 255); // provides power to motor 1
  analogWrite (9, 255); // provides power to motor 2
  Serial.begin(9600);
  // assign the pushbutton pin as an input:
  pinMode(pushButton, INPUT);

  // provides power to servo motor

  myservo.attach(13); // assigns servo to Pin 13

  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);

  //provides power to distance sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}

// the loop function runs over and over again forever
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  // delay in between reads for stability
  delay(1);

  // create if condition for buttonState >= 1
  if (buttonState == 1) {

    moveForward (500); // motors powered on and move forward

    stopMotion (500); // motors powered off

    moveBackward (500); // motors powered on and move backward

    stopMotion (500); // motors powered off
  }



  // read the input on analog pin A0:
  leftSensorValue = analogRead(leftLDR);
  rightSensorValue = analogRead(rightLDR);
  difference = abs(leftSensorValue - rightSensorValue);
  // print out the value you read:
  printOut();

  // value of 50 was chosen rather than 15 to accomodate lighting and increase potential of centering servo
  if (leftSensorValue > rightSensorValue && difference >= 50) {

    moveForward (500);
    delay; (1500);
    myservo.write(180); //left
    delay(1500);
  }

  else if (leftSensorValue < rightSensorValue && difference >= 50) {
    moveBackward (500);
    delay; (1500);
    myservo.write(0); //right
    delay(1500);
  }

  else if (difference <= 50) {
    stopMotion (500);
    delay(1500);
    myservo.write(90); // center
    delay(1500);



  }

{
  long duration, distance;


  // Drive trigger pin LOW, HIGH, LOW to send the pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // low for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // high for 10 microseconds
  digitalWrite(trigPin, LOW);

  // the pulseIn command waits for a given pin to go HIGH, and then
  // reports how long it waited until that happened
  duration = pulseIn(echoPin, HIGH); // measure the time to the echo

  // Convert to centimeters
  distance = (duration / 2) / 29.1; // calculate the distance in cm

  // Discard readings that are too large or too small to be reasonable
  // It's pretty common for some sensors to give occasional bad readings
  // and a good program must take that into account
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range; reading invalid");
    return -1;

  } //else {
  // anything left should be a valid distance
  Serial.print(distance);
  Serial.println(" cm");



}
}

void moveForward (int motionTime) {
  digitalWrite (2, HIGH);   // turn the motor on and move forward (HIGH is the voltage level)
  digitalWrite (4, LOW);
  digitalWrite (7, HIGH);   // turn the motor on and move forward (HIGH is the voltage level)
  digitalWrite (8, LOW);
  delay(motionTime);
}

void stopMotion (int motionTime) {
  digitalWrite (2, LOW);   // turn the motor off for 0.5 second  (LOW is the voltage level)
  digitalWrite (4, LOW);
  digitalWrite (7, LOW);
  digitalWrite (8, LOW);   // wait for 0.5 second
  delay(motionTime);
}

void moveBackward (int motionTime) {
  digitalWrite (2, LOW);
  digitalWrite (4, HIGH);  // turn the motor on a move backward (HIGH is the voltage level)
  digitalWrite (7, LOW);
  digitalWrite (8, HIGH);  // turn the motor on and move forward (HIGH is the voltage level)
  delay(motionTime);       // wait for 0.5 second


}

void printOut() {
  Serial.print("Left Sensor: ");
  Serial.print(leftSensorValue);
  Serial.print(" Right Sensor: ");
  Serial.print(rightSensorValue);
  Serial.print(" Difference: ");
  Serial.println(difference);
  delay(500);        // delay in between reads for stability

}

```
By adding portions of code from several previous assignment's programs such as DC motor functions or servo movements I have provided the robot a small vocabulary of canned phrases that when received via the Morse code key cause a reaction.  My biggest challenge at this point was to have the program reset itself after each input was complete (indicated by a pulse of < 50ms on the push button). In order to prevent it from storing previous input and presenting that along with a new phrase the code  

```
 }
  code = "";                            //reset code to blank string
}
```

needed to be added at the end of the loop.  This reset was necessary in order for the program to be useful.


The variable for output is seemingly endless in this style of communication and is only limited by the programmer's imagination.  I originally started with the goal of driving a record player using a DC motor that would start playing music once the word "play" had been received by Arduino.  For the sake of time, demonstrated the program's ability to translate Morse code with the following commands:

"HI":robot moves back and forth using 2 DC motors based and serial monitor displays message "You really know how to push my buttons"

"YO": a back and forth sweep of the servo motor and serial monitor displays message "Howdy!"

"ON": LED turns on and serial monitor displays message "Let there be light!"

In the future I'd like to explore the use of a cipher/cryptography to add a level of security or challenge to the use of a device running the program.  I'm also interested in building the program's vocabulary to the point where I could upload an entire dictionary and assign a unique response to each word (which could be somewhat predictable or completely random) in order to provide the user of the Morse code key a rich experience.  It could become a guessing game of sorts that challenges them to predict what movement or reaction will take place based on their input.  I really enjoy the vastness of this program's ability to convert analog input into a variety of digital/analog responses that really engage its user.  
  

Morse Code Decoder Responds to Words:

```
//*** Omar Ansari - Arduino Robotics - Summer 2017 - Professor Michael Shiloh
// ** Portion of code provided by instructables.com user pinaki_s91

// attaches servo motor
#include <Servo.h>

Servo myservo;



unsigned long signal_len, t1, t2; //time for which button is pressed
int led = A4;           // the PWM pin the LED is attached to
int inputPin = 10;                 //input pin for push button
int piezoPin = A5;                // analog input for piezo pin
String code = "";                 //string in which one alphabet is stored
String myword = "";
void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT_PULLUP); //internal pullup resistor is used to simplify the circuit
  pinMode(piezoPin, OUTPUT);
  analogWrite (6, 255); // provides power to motor 1
  analogWrite (9, 255); // provides power to motor 2
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  myservo.attach(13); // assigns servo to Pin 13


}

void loop()
{
NextDotDash:
  while (digitalRead(inputPin) == LOW) {}
  t1 = millis();                            //time at button press
  tone(piezoPin, 200);           //piezo speaker tone on while button pressed
  while (digitalRead(inputPin) == HIGH) {}
  t2 = millis();                            //time at button release
  noTone(piezoPin);         //piezo speaker tone on while button pressed
  signal_len = t2 - t1;                     //time for which button is pressed
  if (signal_len > 50)                      //to account for switch debouncing
  {
    code += readio();                       //function to read dot or dash
  }
  while ((millis() - t2) < 500)           //if time between button press greater than 0.5sec, skip loop and go to next alphabet
  {
    if (digitalRead(inputPin) == HIGH)
    {
      goto NextDotDash;
    }
  }
  convertor();                        //function to decipher code into alphabet
}

char readio()
{
  if (signal_len < 600 && signal_len > 50)
  {
    return '.';                        //if button press less than 0.6sec, it is a dot
  }
  else if (signal_len > 600)
  {
    return '-';                        //if button press more than 0.6sec, it is a dash
  }
}

void convertor()
{
  static String letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                             ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"
                            };
  int i = 0;
  if (code == ".-.-.-")
  {
    Serial.print("_");        //for break
  }
  else
  {
    while (letters[i] != "E")  //loop for comparing input code with letters array
    {
      if (letters[i] == code)
      {
        Serial.print(char('A' + i));
        myword += char('A' + i);
        break;
      }
      i++;
    }
    if (letters[i] == "E")
    {
      Serial.println("<input complete>");  //if input code doesn't match any letter, error
      Serial.print("here is the word you typed: ");
      Serial.println(myword);
      if (myword == "HI") {

        Serial.println("You really know how to push my buttons!"); //reponse provided in serial monitor when the word "HI" is typed in followed by short pulse to indicate end of word

        moveForward (500); // motors powered on and move forward

        stopMotion (500); // motors powered off

        moveBackward (500); // motors powered on and move backward

        stopMotion (500); // motors powered off

        moveForward (500); // motors powered on and move forward

        stopMotion (500); // motors powered off

        moveBackward (500); // motors powered on and move backward

        stopMotion (500); // motors powered off

        Serial.println("resetting myword");




      }

      else if (myword == "YO") {

        Serial.println("Howdy!"); //reponse provided in serial monitor when the word "YO" is typed in followed by short pulse to indicate end of word

        myservo.write(180); //left
        delay(1500);
        myservo.write(0); //right
        delay(1500);
        myservo.write(90); // center
        delay(1500);
        myservo.write(180); //left
        delay(1500);
        myservo.write(0); //right
        delay(1500);
        myservo.write(90); // center
        delay(1500);

        Serial.println("resetting myword");

      }

      else if (myword == "ON") {

        Serial.println("Let there be light!"); //reponse provided in serial monitor when the word "ON" is typed in followed by short pulse to indicate end of word

        analogWrite (led, 255);


        Serial.println("resetting myword");

      }
      myword = "";
    }

    //return(char('A' + i));
  }
  code = "";                            //reset code to blank string
}


void moveForward (int motionTime) {
  digitalWrite (2, HIGH);   // turn the motor on and move forward (HIGH is the voltage level)
  digitalWrite (4, LOW);
  digitalWrite (7, HIGH);   // turn the motor on and move forward (HIGH is the voltage level)
  digitalWrite (8, LOW);
  delay(motionTime);
}

void stopMotion (int motionTime) {
  digitalWrite (2, LOW);   // turn the motor off for 0.5 second  (LOW is the voltage level)
  digitalWrite (4, LOW);
  digitalWrite (7, LOW);
  digitalWrite (8, LOW);   // wait for 0.5 second
  delay(motionTime);
}

void moveBackward (int motionTime) {
  digitalWrite (2, LOW);
  digitalWrite (4, HIGH);  // turn the motor on a move backward (HIGH is the voltage level)
  digitalWrite (7, LOW);
  digitalWrite (8, HIGH);  // turn the motor on and move forward (HIGH is the voltage level)
  delay(motionTime);       // wait for 0.5 second


}

```
_______________________________
Thanks for an amazing class Michael!  I'm really excited to keep exploring the possibilities!  Best of luck on your next adventure!
