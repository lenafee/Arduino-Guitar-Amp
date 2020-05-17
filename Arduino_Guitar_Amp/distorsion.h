//This file contains the different overdrive, distorsion and fuzz effects.

//This overdrive uses hard clipping on top and bottom
void overdriveHardClipping(int level, int *input){
    if(*input > level){
        *input = level;
    }
    if(*input < (-level)){
        *input = (-level);
    }
}


//This overdrive uses hard clipping only on the top
void overdrivePositiveHalfHardClipping(int level, int *input){
    if(*input > level){
        *input = level;
    }
}

//This overdrive uses hard clipping only on the bottom and lowers the DC Offset.
void overdriveBiasLevelNegativeHalfHardClipping(int level, int *input){
    *input = *input - 500;
    if(*input < (-level)){
        *input = (-level);
    }
}

//This overdrive uses overdrive soft clip only on the positive side.
void overdrivePositiveSoftClipping(int level, int *input){
    if(*input > level){
        *input = level + *input >> 2;
    }
}

//This overdrive uses softclipping on the top and on the bottom.
void overdriveSoftClipping(int level, int *input){
    if(*input > level){
        *input = level + *input >> 2;
    }
    if(*input < (-level)){
        *input = -level - (*input >> 2);
    }
}

//This overdrive uses hard clipping only on the top and lowers the DC Offset.
void overdriveBiasLevelPositiveHalfHardClipping(int level, int *input){
    *input = *input - 500;
    if(*input > level){
        *input = level;
    }
}

//Metal distorsion. Hard distorsion. Unlike the other distorsion its calculatet by a formula.
void distorsionMetal(int level, int *input){
    *input = (*input/abs(*input))*(1- pow(2.7182818284, ((level * *input)/abs(*input))));
}

//fuzz is the opposite of hard clipped distorsion. Fuzz raises a hard clipp to the max. Volume to min or it will blast your ears off.N
void fuzzExtreme(int level, int *input){
    if(*input > level){
        *input = 15000;
    }
    if(*input < -level){
        *input = -15000;
    }
}

//fuzz is the opposite of hard clipped distorsion. Fuzz raises a hard clipp to the mid level. Max is very extreme.
void fuzz(int level, int *input){
    if(*input > level){
        *input = 10000;
    }
    if(*input < -level){
        *input = -10000;
    }
}
