mycircuitcan
Arduino Class
adding 
'''delay(1);        // delay in between reads for stability''' 
appears to cause more precise serial monitor reading in Analog_Input_With_Sensor_Value sketch.
Sensor values range from 0-1020(minimal ambient light with sensor covered - iPhone flashlight held on top of sensor).  
In comfortable work setting with overhead lighting, LDR value is ~ 695 - 710. 
To test program, sensor was set to "threshold" of 750 as current average LDR value is ~ 695 - 710.  Without additional light from iPhone flashlight value is not sufficient to cause LED to illuminate.  Once additional light is directed toward senso,r LED illuminates as expected.
