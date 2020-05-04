#include "distorsion.c"
#include "generalFunctions.c"
//#include "echo.c"

//defining the output PWM parameters
#define PWM_FREQ 0x00FF // pwm frequency - 31.3KHz
#define PWM_MODE 0 // Fast (1) or Phase Correct (0)
#define PWM_QTY 2 // 2 PWMs in parallel


//other variables
int input, vol_variable=512;
int counter=0;
int ADC_low, ADC_high;
int reverbBuffer[700];
int reverbBufferCounter = 0;


void setup() {
  
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
  
}

ISR(TIMER1_CAPT_vect) 
{
  // get ADC data
  ADC_low = ADCL; // you need to fetch the low byte first
  ADC_high = ADCH;


  
  
  //construct the input sumple summing the ADC low and high byte.

 


//Increse/reset delay counter.   

  
  input = ((ADC_high << 8) | ADC_low) + 0x8000; // make a signed 16b value

  reverbBuffer[reverbBufferCounter] = ADC_high;
  reverbBufferCounter++;
  if(reverbBufferCounter>=700)reverbBufferCounter=0;
  //input = input + (((reverbBuffer[reverbBufferCounter] << 8) | ADC_low) + 0x8000);

  //overdriveBiasLevelNegativeHalfHardClipp(1000, &input);
  //overdriveBiasLevelPositiveHalfHardClipp(1000, &input);
  //overdriveHardClipping(1000, &input);
  //overdrivePositiveHalfHardClipp();
  //overdriveSoftClipping(1000, &input);
  //testOverdrive();
  //distorsionMetal(7, &input);
  //overdrivePositiveSoftClipping(500, &input);
  //overdriveSoftClipping(1000, &input);
  //volume(2, &input);
  //boost(0, &input);
  //boostWithMap(20000, &input);
  //write the PWM signal
  OCR1AL = ((input + 0x8000) >> 8); // convert to unsigned, send out high byte
  OCR1BL = input; // send out low byte

}
