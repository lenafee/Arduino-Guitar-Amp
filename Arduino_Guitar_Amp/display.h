//This file manages the display, buttons and the effect handlig.

#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
//Array of all the available effects.
char* effectNameArray[] = {"Volume", "Boost", "Overdrive 1", "Overdrive 2", "Overdrive 3", "Overdrive 4", "Overdrive 5", "Distorsion 1", "Distorsion 2", "Fuzz", "Reverb", "Crazy Sound"};
//Array to store the current level of each effect.
int effectLevelArray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int effectPointer = 11;

//Different Byte arrays for the start screen.
byte Sound[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};

byte Speaker[] = {
  B00001,
  B00011,
  B01111,
  B01111,
  B01111,
  B00011,
  B00001,
  B00000
};

//The three available buttons of the amp
const int menuButton = 11;
const int levelButtonPlus = 12;
const int levelButtonMinus = 13;
int levelButtonPlusState = 0;
int levelButtonMinusState = 0;
int menuButtonState = 0;

//Creates the start screen for the amp. This will be seen when you boot the amp.
void createStartMonitor(){
    lcd.createChar(1, Speaker);
    lcd.createChar(2, Sound);
    lcd.begin(16, 2);
    lcd.print("    CTAG AMP    ");
    lcd.setCursor(0, 1);
    lcd.write(byte(1));
    lcd.setCursor(3, 1);
    lcd.write(byte(2));
    lcd.setCursor(5, 1);
    lcd.write(byte(2));
    lcd.setCursor(7, 1);
    lcd.write(byte(2));
    lcd.setCursor(9, 1);
    lcd.write(byte(2));
    lcd.setCursor(11, 1);
    lcd.write(byte(2));
    lcd.setCursor(13, 1);
    lcd.write(byte(2));
    lcd.setCursor(15, 1);
    lcd.write(byte(2));
  }

/* 
 *  Handles the screen functions. There are three different buttons.
 *  With the first you can choose the different effects from the list.
 *  The second and third are + and - for the effects.
 */
void showMenu(){
  
    menuButtonState = digitalRead(menuButton);
    levelButtonPlusState = digitalRead(levelButtonPlus);
    levelButtonMinusState = digitalRead(levelButtonMinus);

    //+ Button
    if (levelButtonPlusState == HIGH){
        effectLevelArray[effectPointer]++;
        if(effectLevelArray[effectPointer] > 16) effectLevelArray[effectPointer] = 16;
        for(int i = 0; i < effectLevelArray[effectPointer]; i++){
            lcd.setCursor(i, 1);
            lcd.write(255);
        }
    }

    //- Button
    if (levelButtonMinusState == HIGH){
        effectLevelArray[effectPointer]--;
        if(effectLevelArray[effectPointer] < 0) effectLevelArray[effectPointer] = 0;
        lcd.setCursor(0, 1);
        lcd.print("                ");
        for(int i = 0; i < effectLevelArray[effectPointer]; i++){
            lcd.setCursor(i, 1);
            lcd.write(255);
        }

    }

    //Menu button
    if (menuButtonState == HIGH) {
        effectPointer++;
        if(effectPointer == 12) effectPointer = 0;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(effectNameArray[effectPointer]);
        for(int i = 0; i < effectLevelArray[effectPointer]; i++){
            lcd.setCursor(i, 1);
            lcd.write(255);
        }
    }
}

//Arrays that contain preset levels for most effects.
int volumeArray[16] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000};
int boostArray[16] = {16000, 17000, 18000, 19000, 20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 29000, 30000, 31000};
int overdriveArray[16] = {8000, 7000, 6000, 5000, 4000, 3500, 3000, 2500, 2000, 1800, 1600, 1400, 1200, 1000, 800, 500};


/*
 * This section activates the different effects of the Amp when they are chosen by the
 * Buttons. The Effects activate when the chosen value is >0.
*/
void effectEnableQuery(int *input){
      //Effect 1: Volume 
    if(effectLevelArray[0] > 0){
        volumeWithMap(volumeArray[effectLevelArray[0]-1], input);
    }
      //Effect 2: Boost
    if(effectLevelArray[1] > 0){
        boostWithMap(boostArray[effectLevelArray[1]-1], input);
      }
      //Effect 3: Overdrive 1
    if(effectLevelArray[2] > 0){
        overdriveHardClipping(overdriveArray[effectLevelArray[2]-1], input);
    }
      //Effect 4: Overdrive 2
    if(effectLevelArray[3] > 0){
        overdrivePositiveHalfHardClipping(overdriveArray[effectLevelArray[3]-1], input);
    }
      //Effect 5: Overdrive 3
    if(effectLevelArray[4] > 0){
        overdriveBiasLevelNegativeHalfHardClipping(overdriveArray[effectLevelArray[4]-1], input);
    }
      //Effect 6: Overdrive 4
    if(effectLevelArray[5] > 0){
        overdrivePositiveSoftClipping(overdriveArray[effectLevelArray[5]-1], input);
    }
       //Effect 7: Overdrive 5
    if(effectLevelArray[6] > 0){
        overdriveBiasLevelPositiveHalfHardClipping(overdriveArray[effectLevelArray[6]-1], input);
    }
      //Effect 8: Distorsion 1
    if(effectLevelArray[7] > 0){
        overdriveSoftClipping(overdriveArray[effectLevelArray[7]-1], input);
    }
      //Effect 9: Distorsion 2
    if(effectLevelArray[8] > 0){
        distorsionMetal(7, input);
    }
      //Effect 10: Fuzz
    if(effectLevelArray[9] > 0){
        fuzz(overdriveArray[effectLevelArray[9]-1], input);
    }
      //Effect 11: Reverb
    if(effectLevelArray[10] > 0){
        reverb(input);
    }
      //Effect 12: Crazy Sound
    if(effectLevelArray[11] > 0){
        crazySound();
    }
}
