#include <Servo.h>

Servo myservo;

const int leftLDR = A0;    // pin that the sensor is attached to
const int rightLDR = A1;    // pin that the sensor is attached to


void setup() {
  myservo.attach(13); // assigns servo to Pin 13

  // initialize serial communications:
  Serial.begin(9600);

}

void loop() {

  // read the input on analog pin A0:
  int leftSensorValue = analogRead(leftLDR);
  int rightSensorValue = analogRead(rightLDR);
  // print out the value you read:
  Serial.print("Left Sensor: ");
  Serial.print(leftSensorValue);
  Serial.print(" Right Sensor: ");
  Serial.println(rightSensorValue);
  delay(500);        // delay in between reads for stability

  if (leftSensorValue > rightSensorValue) {
    myservo.write(180); //left
    delay(1500);
  }
  else  {
    myservo.write(0); //right
    delay(1500);
  }

}
