#include "distorsion.c"

//defining the output PWM parameters
#define PWM_FREQ 0x00FF // pwm frequency - 31.3KHz
#define PWM_MODE 0 // Fast (1) or Phase Correct (0)
#define PWM_QTY 2 // 2 PWMs in parallel

//other variables
int input, vol_variable=512;
int counter=0;
byte ADC_low, ADC_high;

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



  void overdriveSoftClipp(int level){
      if(input > level){
          input = input >> 6;
        }
      //if(input < -level){
      //    input = input << 6;
      //  }
    }

  void testOverdrive(){
      if(input > 1000){
          input = 1000 - input;
        }
    }

  void boost(int level){
      //TODO
    }

  void volume(int level){
      //TODO
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
  input = ((ADC_high << 8) | ADC_low) + 0x8000; // make a signed 16b value

  //overdriveBiasLevelNegativeHalfHardClipp(1000, &input);
  //overdriveBiasLevelPositiveHalfHardClipp(1000, &input);
  //overdriveHardClipping(1000, &input);
  //overdrivePositiveHalfHardClipp();
  //overdriveSoftClipp(1000);
  //testOverdrive();
  //distorsionMetal(7, &input);
  //overdrivePositiveSoftClipping(500, &input);
  overdriveSoftClipping(1000, &input);

  input = input*2;
  //write the PWM signal
  OCR1AL = ((input + 0x8000) >> 8); // convert to unsigned, send out high byte
  OCR1BL = input; // send out low byte

}
