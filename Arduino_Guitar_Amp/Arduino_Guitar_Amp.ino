/*
 * This guitarAmp is based on the guitarPedal from Elektrosmash (https://www.electrosmash.com/pedalshield-uno)
 * Licensed under a Creative Commons Attribution 3.0 Unported License.
 * Link to the license: https://creativecommons.org/licenses/by/3.0/de/
 * Based on rcarduino.blogspot.com previous work.
 * www.electrosmash.com/pedalshield
 * The original code is modified.
*/


#include "distorsion.h"
#include "echo.h"
#include "generalFunctions.h"
#include "specialSounds.h"
#include "display.h"


//defining the output PWM parameters
#define PWM_FREQ 0x00FF // pwm frequency - 31.3KHz
#define PWM_MODE 0 // Fast (1) or Phase Correct (0)
#define PWM_QTY 2 // 2 PWMs in parallel


//other variables
int input, vol_variable=512;
int ADC_low, ADC_high;


void setup() {
  //Creates the start screen
  createStartMonitor();

  //Set the buttons as input
  pinMode(menuButton, INPUT);
  pinMode(levelButtonPlus, INPUT);
  pinMode(levelButtonMinus, INPUT);
  
  // setup ADC
  ADMUX = 0x60; // left adjust, adc0, internal vcc
  ADCSRA = 0xe5; // turn on adc, ck/32, auto trigger
  ADCSRB = 0x07; // t1 capture for trigger
  DIDR0 = 0x01; // turn off digital inputs for adc0

  // setup PWM
  TCCR1A = (((PWM_QTY - 1) << 5) | 0x80 | (PWM_MODE << 1)); //
  TCCR1B = ((PWM_MODE << 3) | 0x11); // ck/1
  TIMSK1 = 0x20; // interrupt on capture interrupt
  ICR1H = (PWM_FREQ >> 8);
  ICR1L = (PWM_FREQ & 0xff);
  DDRB |= ((PWM_QTY << 1) | 0x02); // turn on outputs
  sei(); // turn on interrupts - not really necessary with arduino
  }
    

void loop() 
{
   //enables buttons and display
   showMenu();
   //the delay is there to save some workload
   delay(200);
}

ISR(TIMER1_CAPT_vect) 
{
  // get ADC data
  ADC_low = ADCL; // you need to fetch the low byte first
  ADC_high = ADCH;

  //Make a signed 16b value
  input = ((ADC_high << 8) | ADC_low) + 0x8000;

  //Handels the different effects. Activates and deaktivates them. 
  effectEnableQuery(&input);
  
  //write the PWM signal
  OCR1AL = ((input + 0x8000) >> 8); // convert to unsigned, send out high byte
  OCR1BL = input; // send out low byte

}
