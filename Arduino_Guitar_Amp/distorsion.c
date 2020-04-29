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

void overdrivePositiveSoftClipping(int level, int *input){
    if(*input > level){
        *input = level + *input >> 2;
    }
}

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
