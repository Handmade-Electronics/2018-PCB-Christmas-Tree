/* 
 * File:   newmain.c
 * Author: JDG
 * Org: Handmade Electronics
 * Email: owner@HandmadeElectronics.com
 * Revision 2.0
 * Revision includes different order of lights blinking.  Now includes different patterns.
 * Created on October 27, 2018, 11:15 PM
 */
#define _XTAL_FREQ 4000000
#define DELAY 80                // universal delay for blinking
#define LEDC0 0b00001000        //LED<Port><Bit> for easier code reading
#define LEDC1 0b00010000
#define LEDC2 0b00000010
#define LEDC3 0b00100000
#define LEDC4 0b00000100
#define LEDC5 0b00000001
#define LEDA6 0b00010000
#define LEDA7 0b00000010
#define LEDA8 0b00000100
#define LEDA9 0b00100000
#define CLEAR 0b00000000        //switching bits on same port clears previous light
                                //this forces all bits clear when changing ports

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA3/MCLR pin function select (RA3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    TRISA = 0; //set RA pins to output
    PORTA = CLEAR; // Set all ports to off
    TRISC = 0; //set RC pins to output
    PORTC = CLEAR; // Set all ports to off
       
    //Continuous while loop with 3 different patterns
    //comments indicate which LED is turned ON
    //turning on a different LED on the same PORt turns off the last LED
    //if switching to new PORT, the CLEAR has to be used
    while(1)
    {
        //First loop cycles the lights from top to bottom
        for (int i=0; i<9; i++) //Light all LEDs from top to bottom in sequence
        {
            PORTC=LEDC0; __delay_ms(DELAY); //0
            PORTC=LEDC1; __delay_ms(DELAY); //1
            PORTC=LEDC3; __delay_ms(DELAY); //3
            PORTC=LEDC2; __delay_ms(DELAY); //2
            PORTC=LEDC4; __delay_ms(DELAY); //4
            PORTC=LEDC5; __delay_ms(DELAY); //5
            PORTC = CLEAR;
            PORTA=LEDA6; __delay_ms(DELAY); //6
            PORTA=LEDA7; __delay_ms(DELAY); //7
            PORTA=LEDA8; __delay_ms(DELAY); //8
            PORTA=LEDA9; __delay_ms(DELAY); //9
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
        }
        
        //for this second "random" loop, I used a random number generator
        //for the sequence of lights
        
        for (int i=0; i<9; i++) //"random" sequence of lights
        {
            PORTC=LEDC4; __delay_ms(DELAY); //4
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA8; __delay_ms(DELAY); //8
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC1; __delay_ms(DELAY); //1
            PORTC=LEDC5; __delay_ms(DELAY); //5
            PORTC=LEDC2; __delay_ms(DELAY); //2
            PORTC=LEDC0; __delay_ms(DELAY); //0
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA9; __delay_ms(DELAY); //9
            PORTA=LEDA7; __delay_ms(DELAY); //7
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC3; __delay_ms(DELAY); //3
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA6; __delay_ms(DELAY); //6
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC1; __delay_ms(DELAY); //1
            PORTC=LEDC3; __delay_ms(DELAY); //3
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA8; __delay_ms(DELAY); //8
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC2; __delay_ms(DELAY); //2
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA6; __delay_ms(DELAY); //6
            PORTA=LEDA9; __delay_ms(DELAY); //9
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC5; __delay_ms(DELAY); //5
            PORTC=LEDC0; __delay_ms(DELAY); //0
            PORTC=LEDC4; __delay_ms(DELAY); //4
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA7; __delay_ms(DELAY); //7
            PORTA=LEDA9; __delay_ms(DELAY); //9
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC0; __delay_ms(DELAY); //0
            PORTC=LEDC4; __delay_ms(DELAY); //4
            PORTC=LEDC3; __delay_ms(DELAY); //3
            PORTC=LEDC5; __delay_ms(DELAY); //5
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA8; __delay_ms(DELAY); //8
            PORTA=LEDA6; __delay_ms(DELAY); //6
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC2; __delay_ms(DELAY); //2
            PORTC=LEDC1; __delay_ms(DELAY); //1
            PORTC=LEDC3; __delay_ms(DELAY); //3
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA8; __delay_ms(DELAY); //8
            PORTA=LEDA6; __delay_ms(DELAY); //6
            PORTA=LEDA9; __delay_ms(DELAY); //9
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC1; __delay_ms(DELAY); //1
            PORTC=LEDC5; __delay_ms(DELAY); //5
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA7; __delay_ms(DELAY); //7
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC0; __delay_ms(DELAY); //0
            PORTC=LEDC4; __delay_ms(DELAY); //4
            PORTC=LEDC2; __delay_ms(DELAY); //2
        }
        // This third loop cycles from the top to the bottom of the tree
        for (int i=0; i<9; i++) //Light all LEDs from top to bottom & back again
        {
            PORTC=LEDC0; __delay_ms(DELAY); //0
            PORTC=LEDC1; __delay_ms(DELAY); //1
            PORTC=LEDC3; __delay_ms(DELAY); //3
            PORTC=LEDC2; __delay_ms(DELAY); //2
            PORTC=LEDC4; __delay_ms(DELAY); //4
            PORTC=LEDC5; __delay_ms(DELAY); //5
            PORTC = CLEAR;                  // Set all ports to off
            PORTA=LEDA6; __delay_ms(DELAY); //6
            PORTA=LEDA7; __delay_ms(DELAY); //7
            PORTA=LEDA8; __delay_ms(DELAY); //8
            PORTA=LEDA9; __delay_ms(DELAY); //9
            PORTA=LEDA8; __delay_ms(DELAY); //8
            PORTA=LEDA7; __delay_ms(DELAY); //7
            PORTA=LEDA6; __delay_ms(DELAY); //6
            PORTA = CLEAR;                  //CLEAR PORT A LEDs
            PORTC=LEDC5; __delay_ms(DELAY); //5
            PORTC=LEDC4; __delay_ms(DELAY); //4
            PORTC=LEDC2; __delay_ms(DELAY); //2
            PORTC=LEDC3; __delay_ms(DELAY); //3
            PORTC=LEDC1; __delay_ms(DELAY); //1
        }
    }
}