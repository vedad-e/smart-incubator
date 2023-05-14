# Smart Incubator
The project, which was carried out as part of the course "Mechatronic systems", whose goal was to improve the functionality of the incubator

### How does it works
The incubator has an LCD display, on which the temperature and humidity inside the incubator are printed at all times.
When the temperature rises above a certain threshold, the fan starts working to cool the incubator. If a critical temperature is reached, an alarm is triggered.

### Components
+ Arduino UNO
+ LCD 16x2
+ Fan 5V DC
+ DHT11
+ Buzzer
+ LED Diodes

### Work algorithm
When the temperature is below 27 degrees, the green LEDs are lit, indicating that the temperature inside the incubator is satisfactory.
If the temperature is between 27 and 30 degrees, the green LEDs are turned off and the fan is turned on until the temperature drops below 27 degrees.
In the case of a critical temperature above 30 degrees, an alarm (buzzer) lights up and the red LEDs start flashing.

###Photos of the project
