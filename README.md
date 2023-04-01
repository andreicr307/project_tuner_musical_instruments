# Project_Tuner_for_Musical_Instruments
Digital-analog converter made up of a resistive R2R network. 
The DAC converter receives a 6-bit digital signal that it transforms into a single analog signal.

The signal is received at the output of the DAC by an operational amplifier (LM358) to filter it, then it is passed through an FTJ filter after which it is received by 2 amplifiers (LM358) arranged in antiphase for signal amplification.
The DAC converter receives a 6-bit digital signal that it transforms into a single analog signal.

User interface

- For the user interface we used a 1602 LCD with which we can view the menu
- 3 buttons to navigate the menu
- 6 LEDs, one for each bit of the DAC, to show which bits are active at certain times.
- The launchpad microcontroller MSP430G2553

Software implementation in energia/arduino
