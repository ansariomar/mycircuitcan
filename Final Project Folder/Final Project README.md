
delay time must be at least 2x the length of duration of tone in order to hear audible pause between multiple tones
lowest accurate tone possible is 31 hz although values are unsigned integers audible from 0 to 65,535
cannot use analogWrite() on pin # 3 & 11 while using the tone function because tone function uses the same built-in timer that analog write uses for pin # 3 & 11

 /*tone needs 2 arguments to work, but can take three
     1) Pin#
     2) Freq - value in hertz
  */ 3) Duration
creating a tone:

```// simple piezo speaker tone
// speaker is attached to pin A5 and analog ground

int piezoPin = A5;

void setup() {

}//close setup

// delay time must be at least 2x the length of duration of tone in order to hear audible pause between multiple tones
// lowest accurate tone possible is 31 hz although values are unsigned integers audible from 0 to 65,535
// cannot use analogWrite() on pin # 3 & 11 while using the tone function because tone function uses the same built-in timer that analog write uses for pin # 3 & 11

void loop() {

  /*tone needs 2 arguments to work, but can take three
     1) Pin#
     2) Freq - value in hertz
     3) Duration
  */

  //create a tone
  tone(piezoPin, 100, 500);

  delay (1000);

  tone(piezoPin, 31 , 500);

  delay (1000);

}
````

Program now recognizes when canned phrases have been input through Morse code by adding:

```
{
      Serial.println("<Wrong input>");  //if input code doesn't match any letter, error
      Serial.print("here is the word you typed: ");
      Serial.println(myword);
      if (myword == "HI") {
        Serial.println("You really know how to press my buttons!");
      }
      Serial.println("resetting myword");
      myword = ""; // reset myword to a blank string for next word
    }
    //return(char('A' + i));
  }
  ````
  Next step is to move from a response within the "serial monitor" to an action performed by a peripheral i.e. DC motor or piezo speaker playing 8-bit music.


Success!  By adding:

``` if (myword == "HI") {
        moveForward (500); // motors powered on and move forward

        stopMotion (500); // motors powered off
        Serial.println("You really know how to press my buttons!"); //reponse provided in serial monitor when the word "HI" is typed in followed by short pulse to indicate end of word
      }
      Serial.println("resetting myword");
      myword = ""; // reset myword to a blank string for next word
    }
    ```
    
    the program now understands that the a word is a command for an action.  Now time to test the limits.
