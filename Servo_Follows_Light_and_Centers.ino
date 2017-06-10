#include <Servo.h>

Servo myservo;

const int leftLDR = A0;    // pin that the sensor is attached to
const int rightLDR = A1;    // pin that the sensor is attached to
int leftSensorValue;
int rightSensorValue;
int difference;

void setup() {
  myservo.attach(13); // assigns servo to Pin 13

  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {

  // read the input on analog pin A0:
  leftSensorValue = analogRead(leftLDR);
  rightSensorValue = analogRead(rightLDR);
  difference = abs(leftSensorValue - rightSensorValue);
  // print out the value you read:
  printOut();

  // value of 50 was chosen rather than 15 to accomodate lighting and increase potential of centering servo
  if (leftSensorValue > rightSensorValue && difference >= 50) {

    myservo.write(180); //left
    delay(1500);
  }

  else if (leftSensorValue < rightSensorValue && difference >= 50) {
    myservo.write(0); //right
    delay(1500);
  }

  else if (difference <= 50) {
    myservo.write(90); // center
    delay(1500);

  }

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
