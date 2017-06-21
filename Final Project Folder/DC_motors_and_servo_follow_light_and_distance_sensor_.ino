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

