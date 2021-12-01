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

