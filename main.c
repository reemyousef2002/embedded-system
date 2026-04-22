/**
 * @file main.c
 * @Reem Yousef Haboush 220201788
 * @brief LED Blinking using Hardware Timer Interrupts
 * @version 0.1
 * @date 2026-04-22
 * * @description:
 * This program toggles an LED connected to a specific GPIO pin 
 * using Timer1 interrupts. This approach is more efficient than 
 * using software delays as it frees up the CPU to perform other tasks.
 */

#include <avr/io.h>
#include <avr/interrupt.h>

// Define the LED pin (e.g., Port B, Pin 5 - common on Arduino Uno)
#define LED_PIN PB5

/**
 * @brief Initializes Timer1 in CTC mode
 * CTC (Clear Timer on Compare Match) allows us to set a precise frequency.
 */
void timer1_init() {
    // Set Timer1 to CTC mode (Clear Timer on Compare Match)
    TCCR1B |= (1 << WGM12);
    
    // Set the compare value for a 500ms interval (assuming 16MHz clock)
    // Formula: Target_Value = (Clock_Freq / (Prescaler * Target_Freq)) - 1
    OCR1A = 31249;
    
    // Set Prescaler to 256
    TCCR1B |= (1 << CS12);
    
    // Enable Timer1 Output Compare A Match Interrupt
    TIMSK1 |= (1 << OCIE1A);
}

int main(void) {
    // Configure the LED pin as an OUTPUT
    DDRB |= (1 << LED_PIN);
    
    // Initialize the hardware timer configuration
    timer1_init();
    
    // Enable Global Interrupts (Set the I-bit in SREG)
    sei();

    /**
     * The main loop remains empty or handles other low-priority tasks.
     * The hardware interrupt will handle the LED toggling automatically.
     */
    while (1) {
        // CPU can perform other background calculations here
    }
}

/**
 * @brief Interrupt Service Routine (ISR) for Timer1 Compare Match A
 * This function runs every time the timer reaches the value in OCR1A.
 */
ISR(TIMER1_COMPA_vect) {
    // Toggle the LED state using the XOR bitwise operator
    PORTB ^= (1 << LED_PIN);
}