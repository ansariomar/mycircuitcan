const int led1Pin = 9;
const int led2Pin = 4;



const int led10Pin = 7;
const int ledPins [] = {9, 4, 7, 2, 3, 5, 6, 8, 12, 11};

//or
//const int ledPins[10];

void setup () {


  for (int i = 0; i < 10; i = i + 1) {
    pinMode(ledPins[i], OUTPUT);
    Serial.begin(9600);
    Serial.println(ledPins[i]);
    delay(1000);



  }
}


void loop () {

}

