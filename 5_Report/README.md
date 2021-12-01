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

* Reset - ATMEGA328P Pin-PC6
* Minutes increment - ATMEGA328P Pin-PC1
* Hours increment - ATMEGA328P Pin-PC2

# 7-SEGMENTS-CLOCK #
# Requirements
## Features
- Connecting 7-Segment display with ATmaga328 microcontroller.
- Interfacing 7-segment display using Embedded c programming.
- Communicating with 7-segment display.

## State of art research/Research
This article is about the ATMega328 and how to control it with a 7-segment display. Everything is programmed in C with Amtel Studio. The software is loaded to the microcontroller via a programmer (AVRISP). The display is connected to PORTD with a 4-bit line.

### *How the 7-segment display works*
The 7-segment displays are really just seven LEDs lined up in a particular pattern. ... Each of the seven LEDs is called a segment because when illuminated the segment forms part of a numerical digit (both Decimal and Hex) to be displayed. An additional 8th LED is sometimes used for indication of a decimal point.

## Using four 7-Segments Displays
You can see in the final result project image that I used a 7 Segments Display array, already multiplexed and easier to be used.
Before use the 7 Segments Array I tested the circuit and the code in a breadboard with four 7 Segments Displays.
The only difference is that you need to multiplex the pins manually and connect a resistor between microcontroller port and display control pins.
In the other hand, using the 7 Segments Display array it is not necessary to connect the display resistors because they are considered in its internal circuit.

## Swot analysis
###  - *Strength*
-   Used in almost every embedded devices.
-   Required to show key things in embedded system
-   Low cost and easly available in market.

### -   *Weakness*
-   Some embedded devices don't need display.
-   Only small amout of information can be displayed.


### - *Opportunities*
-   With Increase of IOT devices more 7-segment Interfacing required.
-   Can Used in different Microcontrollers. 
 
### - *Threats*
-   Intrefacing with Other display devices may leads to a threat.
-   Working in different environmental conidtions.
   
## 4W and 1H
### -   Who
-   Y.Lakshmi Pavan Kalyan Reddy try to implement this problem statement.

### - What
-  Implementation of embedded device that works as clock with 7-segment.

### -  Where
-   It is a embedded device implemented on ATmega328 microcontroller.

### -   How
-    This can be implemented using embedded c dumped into the microcontroller.

## Components used in project
|S.no| Qty| Components|
|----|----|----------|
|1 |1 | ATMEGA328P microcontroller |
|2 |1 | 28 pins header |
|3|3|Push button|
|4|3|Resistor 1k ohm (+4 if you use four 7 Segments Display)|
|5|1|16MHz Crystal|
|6|2|22pF Capacitors|
|7|1|100nF Capacitors|
|8|1|7 Segments Display Array|
|9|1|Female P4 Jack|
|10|1|10x5cm Universal Soldering Board|

