// the setup function runs once when you press reset or power the board
void setup() {
 // initialize digital pin LED_BUILTIN as an output.
 pinMode (2, OUTPUT);
 pinMode (4, OUTPUT);
 pinMode (6, OUTPUT);

 analogWrite (6, 255);
}

// the loop function runs over and over again forever
void loop() {
 digitalWrite (2, HIGH);   // turn the LED on (HIGH is the voltage level)
 digitalWrite (4, LOW);
 delay(1000);                       // wait for a second

 digitalWrite (2, LOW);   // turn the LED on (HIGH is the voltage level)
 digitalWrite (4, LOW);
 delay(1000);

 digitalWrite (2, LOW);   // turn the LED on (HIGH is the voltage level)
 digitalWrite (4, HIGH);
 delay(1000);                       // wait for a second

 digitalWrite (2, LOW);   // turn the LED on (HIGH is the voltage level)
 digitalWrite (4, LOW);
 delay(1000);

}
