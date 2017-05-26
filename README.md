# HW-1
Arduino Class
adding '''delay(1);        // delay in between reads for stability''' appears to cause more precise serial monitor reading in Analog_Input_With_Sensor_Value sketch.
Sensor values range from 0-1020(minimal ambient light with sensor covered - iPhone flashlight held on top of sensor).  
In comfortable work setting with overhead lighting, LDR value is ~ 695 - 710 
Set sensor "threshold" to 750 when average LDR value is ~ 695 - 710 to test sketch.  Without additional light from iPhone flashlight value is not sufficient to cause LED to illuminate.  Once additional light is directed toward sensor LED illuminates as expected.
