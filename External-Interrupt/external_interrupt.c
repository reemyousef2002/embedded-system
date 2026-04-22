/**
 * @file external_interrupt.c
 * @Reem Yousef Haboush
 * @brief Handling External Events using Interrupts
 * @description:
 * This project demonstrates how to trigger an action based on an external
 * hardware signal (like a sensor or button) using External Interrupt (INT0).
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_PIN PB5     // LED on Pin 13
#define BUTTON_PIN PD2  // External Interrupt 0 (INT0) is on PD2

void ext_interrupt_init() {
    // Configure PD2 as input
    DDRD &= ~(1 << BUTTON_PIN);
    // Enable pull-up resistor for the button
    PORTD |= (1 << BUTTON_PIN);

    // Trigger INT0 on falling edge (button pressed)
    EICRA |= (1 << ISC01);
    EICRA &= ~(1 << ISC00);

    // Enable External Interrupt 0
    EIMSK |= (1 << INT0);
}

int main(void) {
    // Set LED pin as output
    DDRB |= (1 << LED_PIN);
    
    ext_interrupt_init();
    sei(); // Enable global interrupts

    while (1) {
        // Main loop can be used for low-power mode or other tasks
    }
}

// ISR for External Interrupt 0
ISR(INT0_vect) {
    // Toggle LED when button is pressed
    PORTB ^= (1 << LED_PIN);
}
