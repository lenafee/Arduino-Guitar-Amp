int reverbBuffer[800];
int reverbBufferCounter = 0;

void reverb(int *input){
    reverbBuffer[reverbBufferCounter] = *input;
    reverbBufferCounter++;
    if(reverbBufferCounter>=799)reverbBufferCounter=0;
    *input = *input + reverbBuffer[reverbBufferCounter];
  }
