# Stopwatch  Embedded System - ATmega32

This repository contains the implementation of a Stopwatch system using the ATmega32 Microcontroller. The Stopwatch is designed to count time using Timer1 in CTC mode and display the elapsed time on six Common Anode 7-segment displays. The project utilizes multiplexing techniques to control the displays and includes features such as start, pause, reset, and resume using external interrupts.

## Table of Contents

- [Requirements](#requirements)
- [Released Versions](#released-versions)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Usage](#usage)

---
## Requirements
Check [The Mini Project 2 requirements file](https://github.com/Hesham-Hesham/Stopwatch-Embedded-System-ATmega32/blob/main/Mini%20Project%202%20requirements.pdf)

---
## Released Versions
### 1. Unlayered
This version is **built from a single main.c file and is not based on a layered architecture**.

<br/><br/>

### 2. V1_Layered
![V1 Layered](https://github.com/Hesham-Hesham/Stopwatch-Embedded-System-ATmega32/assets/91581641/69252647-b255-429d-a218-ed7648238a3f)

This version is similar to the unlayered version but the difference is that it's **based on a layered architecture model** using the default hardware components which are:
 - Six Common Anode 7-segment displays
 - 7447 BCD-to-7-segment decoder

<br/><br/>

### 3. V2_Layered

![V2 Layered](https://github.com/Hesham-Hesham/Stopwatch-Embedded-System-ATmega32/assets/91581641/233e5a95-08c2-4965-bb2e-d9f400e305ad)


 This version is also built from a layered architecture model but it **uses an LCD instead of thes six common anode 7-segment displays**.

---
## Components

The project utilizes the following components:

- ATmega32 Microcontroller
- Six Common Anode 7-segment displays
- 7447 BCD-to-7-segment decoder
- NPN BJT transistors
- Push buttons (with internal pull-up and external pull-down resistors)
- LCD

---

## Circuit Diagram

![image](https://github.com/Hesham-Hesham/Stopwatch-Embedded-System-ATmega32/assets/91581641/812a2a99-1174-4787-ab65-279767595fac)


---

## Usage
- ### Hardware target
    In order to run the code on a real hardware target (ARmega32), follow these steps:
1. **Setup**: Connect the components as per the circuit diagram.
2. **Compile**: Use an appropriate compiler (e.g., AVR GCC) to compile the provided source code.
3. **Program**: Program the ATmega32 Microcontroller with the compiled binary using a suitable programmer (e.g., AVR ISP).
4. **Run**: Power up the circuit. The Stopwatch will start counting immediately.
5. **User Interaction**: Use the push buttons as follows:
   - Press the reset button (connected to INT0) to reset the Stopwatch time.
   - Press the pause button (connected to INT1) to pause the Stopwatch time.
   - Press the resume button (connected to INT2) to resume the Stopwatch time.

- ### Simulation
1.  **Setup**: Install proteus 8 professional v10.0 or higher
2. **Install Add-ons**: Add the necessary arduino and avr add-ons (Arduino_Proteus_Libraries)
3. **Run**: Run the .pdsprj file in the /Proteus Simulation folder in any of the versions 

---

This project's unlayered version was made during the Full Embedded Systems Diploma under the supervision of Engineer Mohamed Tarek.

---

*Note: This README provides an overview of the project and its requirements. For detailed implementation and code, please refer to the source files provided in this repository.*
