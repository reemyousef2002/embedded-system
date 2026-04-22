# Task 2: External Interrupt Handling

## Description
This project demonstrates how to handle asynchronous external events using **External Interrupts (INT0)**. The system monitors a specific input pin (connected to a button or sensor) and toggles an LED immediately when a signal is detected, without polling the pin in the main loop.

## Key Concepts
- **External Interrupts**: Using the microcontroller's hardware to sense voltage changes.
- **Interrupt Service Routine (ISR)**: Executing a specific function when the event occurs.
- **I/O Configuration**: Setting up pins as inputs with internal pull-up resistors.

## How it Works
1. **Pin PD2** is configured as an input with an enabled pull-up resistor.
2. The **EICRA** register is configured to trigger an interrupt on the **Falling Edge** (when the button is pressed).
3. When the event is detected, the CPU pauses the main loop and executes `ISR(INT0_vect)`.
4. The LED on **PB5** is toggled using the Bitwise XOR operator.

## Files
- `external_interrupt.c`: Source code for the interrupt configuration and ISR.
## Author
Reem Yousef Haboush
