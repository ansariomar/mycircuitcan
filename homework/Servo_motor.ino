#include <Servo.h>

Servo myservo;

void setup () {
  myservo.attach(9);
}
void loop() {
  long left, forward, right;

  myservo.write(0);
  delay(1500);

  myservo.write(90);
  delay(1500);

  myservo.write(180);
  delay(1500);
}

