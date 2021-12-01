# 7-Segments-Clock
## The purpose
* This is a 7 Segments Clock project, developed from zero, using authoral hardware and software. The clock marks hours, minutes and seconds, using an ATMEGA328P microcontroller,     from ATMEL. The 7 Segments Clock was developed as a personal project and it was built on an universal soldering breadboard, according with Proteus folder schematics inside this   project. 

## Utility
* The code was developed specifically to ATMEGA328P microcontroller using ATMEL Studio IDE. However, if some changes were made, mainly in initialization, configuration and some     registers, the project can be adapted to other microcontroller families, from other manufacturers and IDEs. The idea to build a 7 Segments Clock is the same, but some things       will change, like timer registers, I/O and ADC configurations.

# How it works?
* The clock starts marking time from 00:00, in the moment that it's powered. To adjust time until desired hour and minute you have to use the circuit push buttons (in the right side of microcontroller). We have two push buttons, one to increment hours and another one to increment minutes.

* This project algorithm marks hours, minutes and seconds, but it was built only with 4 displays, marking hours and minutes. However, if you want to build a full clock (using seconds markers too) it is only necessary to add two 7 Segments displays and connect it on 2 non used microcontroller ports.

* The code was developed with the full clock logic, but when I burn it to microcontroller I comment one of markers (seconds, for example - "CalculateSeconds" function) and it marks Hours + Minutes. In the other hand, if I want to see Minutes + Seconds you need to comment "CalculateHours" function and it will display Minutes + Seconds.

* In the moment that the circuit is de-energized, the clock loses its reference and the current time because it does not have a memory hardware implemented in circuit.

# Use of Push Buttons:

Reset - ATMEGA328P Pin-PC6
Minutes increment - ATMEGA328P Pin-PC1
Hours increment - ATMEGA328P Pin-PC2
