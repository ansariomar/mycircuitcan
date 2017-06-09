#include <Servo.h>

Servo myservo;



void setup() {
  //ouihihyvb
  myservo.attach(9);

  Serial.begin(9600);
  Serial.begin(9600);
}


void loop() {

  // lightSensor Inputs
  int sensorValue_1 = analogRead(A0);
  int sensorValue_2 = analogRead(A1);

  //print sensorValues
  Serial.println(sensorValue_1);
  //Serial.println(" _sns1");
  delay(1);
  Serial.println(sensorValue_2);
  //Serial.println(" _sns2");
  delay(1);


  //  long left, forward, right;
  //  myservo.write(0);
  //  delay(1500);
  //
  //  myservo.write(90);
  //  delay(1500);
  //
  //  myservo.write(190);
  //  delay(1500);

  // if the difference between the two sensors > 15 then the motor turn 90
  if (abs (sensorValue_1 - sensorValue_2) < 15 {
    myservo.write(90);
    Serial.println("less than 15");

    // if not > 15 the motor follow the highr value sensor
  } else {
    if (sensorValue_1 > sensorValue_2) {
      myservo.write(0);
    } else {
      myservo.write(180);
    }
  }
}
