/*
 * This File contains the reverb of the Amp. The Arduino has very limitet
 * amount of memory and so the length of the reverb is very limited. The
 * buffer is set to the max limit. Unlike distorsions you can not choose
 * the level of the reverb yourself because the range is so limited and is
 * already at the max limit.
 */

int reverbBuffer[800];
int reverbBufferCounter = 0;

void reverb(int *input){
    reverbBuffer[reverbBufferCounter] = *input;
    reverbBufferCounter++;
    if(reverbBufferCounter>=799)reverbBufferCounter=0;
    *input = *input + reverbBuffer[reverbBufferCounter];
  }
