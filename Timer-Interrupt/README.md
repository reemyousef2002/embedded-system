# Embedded Systems Project: Timer-Based LED Control

## Description
This project demonstrates the use of hardware timers and interrupts in embedded systems. Instead of using inefficient software delays (`delay_ms`), this program utilizes **Timer1** in **CTC (Clear Timer on Compare Match)** mode to toggle an LED every 500ms.

## Features
- **Efficient CPU Usage**: Uses hardware interrupts to free up the processor for other tasks.
- **Precision**: Hardware timers provide more accurate timing than loop-based delays.
- **Clean Code**: Written in Embedded C with professional Doxygen-style documentation.

## Hardware Components (Generic)
- Microcontroller (e.g., ATmega328P / Arduino Uno)
- LED connected to PB5 (Digital Pin 13)
- Current-limiting resistor (220Ω)

## How It Works
1. The **Timer1** is configured with a prescaler of 256.
2. The **OCR1A** register is set to 31249 to trigger an interrupt every 0.5 seconds.
3. When the timer matches this value, the **Interrupt Service Routine (ISR)** is executed.
4. Inside the ISR, the LED state is toggled using the **XOR** bitwise operator.

## Files
- `main.c`: The core source code containing peripheral initialization and interrupt handling.

## Author
Reem Yousef Haboush
