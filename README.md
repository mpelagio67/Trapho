# TRAPHO

TRAPHO is a Firmware developed to control Coil Winding Machines. It can be code dumped to a Trapho MicroControlled Board 
based on STM32F103C6T6 or STM32F103C8T6 microcontroller by ST Microelectronics.

Basicly, TRAPHO BOARD AND FIRMWARE is a System that has some type of sensor that detects and generate a digital LOW LEVEL PULSE 
for each turn made by the controled Machine.

That System has a KEYBOARD INTERFACE to set a desired number of coil turns and some other parameters and functions (ex: speed, 
warning sounds, start and stop, etc).

It also has an OLED INTERFACE to visualize those parameters and the winding progress and a Basic 'BEEP' INTERFACE.

Additionally, the TRAPHO BOARD provides additional inputs for connecting extra sensors for future versions of the Firmware and/or 
to facilitate different future applications of the system in controlling other machines or in industrial automation.

The System also has PWM control to command a power interface and thus control the winding speed of the coil turns 
and 4 other OUTPUTS that controls 4 RELAYS that can be used to control another parts of the machine or for another applicatons 
outside the scope of this project. 

In this case, as it is not the objective of this project, the Firmware DOES NOT HAVE SUPPORT FOR THESE EXTRA OUTPUTS AND SENSORS and 
requires additional code specific to the intended application.

For applications other than the Objective of this project, the Firmware and even the original electronic project can be easily 
modified and/or adapted.

TODO LIST:

1- Publish Electronic Schematic for TRAPHO BOARD

