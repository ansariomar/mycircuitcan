mycircuitcan
Arduino Class
Analog_Input_With_Sensor_Value program; adding ```delay(1);        // delay in between reads for stability```appears to cause more precise serial monitor reading.
Sensor values range from 0-1020(minimal ambient light with sensor covered - iPhone flashlight held on top of sensor).  
In comfortable work setting with overhead lighting, LDR value is ~ 695 - 710. 
If_LDR_Greater_Than_750_LED_On; to test program, sensor was set to "threshold = 750" as current average LDR value is ~ 695 - 710.  Without additional light from iPhone flashlight value is not sufficient to cause LED to illuminate.  Once additional light is directed toward sensor, LED illuminates momentarily as expected.
If_LDR_Greater_Than_750_LED_On; by adding ```else {analogValue < 650;``` to this program LDR readings above 750 cause LED to remain on.  No analog input appears to turn off the LED.  Discovered while attempting to find code to "modify the program so that the LED turns on when the light level is above some threshold (say 700), turns off when the light level is below a different threshold (say 300), and blinks if the light level is between those two thresholds." 
