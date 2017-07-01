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


