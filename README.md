# Stopwatch System with ATmega32 Microcontroller

This repository contains the implementation of a Stopwatch system using the ATmega32 Microcontroller. The Stopwatch is designed to count time using Timer1 in CTC mode and display the elapsed time on six Common Anode 7-segment displays. The project utilizes multiplexing techniques to control the displays and includes features such as start, pause, reset, and resume using external interrupts.

## Table of Contents

- [Requirements](#requirements)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)


## Requirements

To implement the Stopwatch system, the following requirements were fulfilled:

1. Use of ATmega32 Microcontroller with a frequency of 1MHz.
2. Configuration of Timer1 in ATmega32 with CTC mode for time counting.
3. Utilization of six Common Anode 7-segment displays.
4. Multiplexed display technique using a 7447 decoder for all 7-segments and NPN BJT transistors for enable/disable control.
5. Implementation of Multiplexing to display one 7-segment at a time, creating a persistent visual display.
6. Connection of the first 4-pins of PORTC to the 7447 decoder and first 6-pins of PORTA for enable/disable control of the six 7-segments.
7. Automatic start of Stopwatch counting upon power connection to the MCU.
8. Configuration of External Interrupt INT0 with a falling edge to reset the Stopwatch time using a push button with internal pull-up resistor.
9. Configuration of External Interrupt INT1 with a rising edge to pause the Stopwatch time using a push button with an external pull-down resistor.
10. Configuration of External Interrupt INT2 with a falling edge to resume the Stopwatch time using a push button with internal pull-up resistor.

## Components

The project utilizes the following components:

- ATmega32 Microcontroller
- Six Common Anode 7-segment displays
- 7447 BCD-to-7-segment decoder
- NPN BJT transistors
- Push buttons (with internal pull-up and external pull-down resistors)
- External crystal oscillator (1MHz)
- Capacitors and resistors as required for circuit stability

## Circuit Diagram


## Usage

1. **Setup**: Connect the components as per the circuit diagram.
2. **Compile**: Use an appropriate compiler (e.g., AVR GCC) to compile the provided source code.
3. **Program**: Program the ATmega32 Microcontroller with the compiled binary using a suitable programmer (e.g., AVR ISP).
4. **Run**: Power up the circuit. The Stopwatch will start counting immediately.
5. **User Interaction**: Use the push buttons as follows:
   - Press the reset button (connected to INT0) to reset the Stopwatch time.
   - Press the pause button (connected to INT1) to pause the Stopwatch time.
   - Press the resume button (connected to INT2) to resume the Stopwatch time.


