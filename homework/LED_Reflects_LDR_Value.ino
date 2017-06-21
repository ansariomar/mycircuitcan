
  int ledPin = 11;      // LED connected to digital pin 11

int analogPin = A0;   // potentiometer connected to analog pin Ao

int val = 0;         // variable to store the read value



void setup()

{

  pinMode(ledPin, OUTPUT);   // sets the pin as output

}



void loop()

{

  val = analogRead(analogPin);   // read the input pin

  analogWrite(ledPin, val / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
}


