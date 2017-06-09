// declare variable pushButton and give it a value of "10" (for pin number 10)
int pushButton = 10;

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);

  analogWrite (6, 255); // provides power to motor 1
  analogWrite (9, 255); // provides power to motor 2
  Serial.begin(9600);
  // assign the pushbutton pin as an input:
  pinMode(pushButton, INPUT);

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

    digitalWrite (2, HIGH);   // turn the motor on and move forward (HIGH is the voltage level)
    digitalWrite (4, LOW);
    digitalWrite (7, HIGH);   // turn the motor on and move forward (HIGH is the voltage level)
    digitalWrite (8, LOW);

    delay(500);                       // wait for 0.5 second

    digitalWrite (2, LOW);   // turn the motor off for 0.5 second  (LOW is the voltage level)
    digitalWrite (4, LOW);
    digitalWrite (7, LOW);
    digitalWrite (8, LOW);
    delay(500);

    digitalWrite (2, LOW);   // turn the motor on a move backward (HIGH is the voltage level)
    digitalWrite (4, HIGH);
    digitalWrite (7, LOW);
    digitalWrite (8, HIGH);
    delay(500);                       // wait for 0.5 second

    digitalWrite (2, LOW);   // turn the motor off for 0.5 second (HIGH is the voltage level)
    digitalWrite (4, LOW);
    digitalWrite (7, LOW);
    digitalWrite (8, LOW);
    delay(500);

  }
  }
