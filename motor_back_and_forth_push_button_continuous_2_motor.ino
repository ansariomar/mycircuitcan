// declare variable pushButton and give it a value of "10" (for pin number 10)
int pushButton = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);


  // power motors using analog write to control speed. Motor on pin 6 is 175
  analogWrite (6, 255);
  analogWrite (9, 255);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // assign the pushbutton pin as an input:
  pinMode(pushButton, INPUT);
}

// create loop function for sequence
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  // delay in between reads for stability
  delay(1);

  // create if condition for buttonState >= 1
  if (buttonState == 1) {

    // make wheels move forward for 1/4 second (250 miliseconds)


    // make wheel stop for 1/4 second (250 miliseconds)
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (7, LOW);
    digitalWrite (8, LOW);
    delay(250);

    // make robot move backwards for 1/4 second (250 miliseconds)
    digitalWrite (2, LOW);
    digitalWrite (4, HIGH);
    digitalWrite (7, LOW);
    digitalWrite (8, HIGH);
    delay(250);

    // make robot stop for half 1/4 second (250 miliseconds). Turning off power allows wheels to stop before moving forward at the beginning of the next loop.
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (7, LOW);
    digitalWrite (8, LOW);
    delay(250);

    while (1) { // while (1) causes single press of button to act as though it being held continuously
      // make wheels move forward for 1/4 second (250 miliseconds)
      digitalWrite (2, HIGH);
      digitalWrite (4, LOW);
      digitalWrite (7, HIGH);
      digitalWrite (8, LOW);
      delay(250);

      // make wheel stop for 1/4 second (250 miliseconds)
      digitalWrite (2, LOW);
      digitalWrite (4, LOW);
      digitalWrite (7, LOW);
      digitalWrite (8, LOW);
      delay(250);

      // make robot move backwards for 1/4 second (250 miliseconds)
      digitalWrite (2, LOW);
      digitalWrite (4, HIGH);
      digitalWrite (7, LOW);
      digitalWrite (8, HIGH);
      delay(250);

      // make robot stop for half 1/4 second (250 miliseconds). Turning off power allows wheels to stop before moving forward at the beginning of the next loop.
      digitalWrite (2, LOW);
      digitalWrite (4, LOW);
      digitalWrite (7, LOW);
      digitalWrite (8, LOW);
      delay(250);
    }


  }

}
