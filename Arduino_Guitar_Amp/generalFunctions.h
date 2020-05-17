/*
 *  Contains the volume and boost functions. They do not work very well
 *  because of the map fuction. The workload is a little bit to much for
 *  the uno.
  */

void volume(int level , int *input){
    *input = *input >> level;
}

void volumeWithMap(int boostValue, int *input){
   *input = map(*input, -32768, +32768,-boostValue, boostValue);
}


void boost(int active , int *input){
    *input = *input << 2;
}

void boostWithMap(int boostValue, int *input){
   *input = map(*input, -32768, +32768,-boostValue, boostValue);
}

//TODO implement some filters
