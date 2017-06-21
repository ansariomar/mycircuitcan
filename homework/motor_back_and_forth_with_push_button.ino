// declare variable pushButton and give it a value of "7" (for pin number 7)
int pushButton = 7;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
 

  // power motors using analog write to control speed. Motor on pin 6 is 175
  analogWrite (6, 175);
  
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
    digitalWrite (2, HIGH);
    digitalWrite (4, LOW);
    delay(250);

    // make wheel stop for 1/4 second (250 miliseconds)
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    delay(250);

    // make robot move backwards for 1/4 second (250 miliseconds)
    digitalWrite (2, LOW);
    digitalWrite (4, HIGH);
    delay(250);

    // make robot stop for half 1/4 (250 miliseconds). Turning off power allows wheels to stop before moving forward at the beginning of the next loop.
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    delay(250);

    


  }

}
