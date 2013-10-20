#include <cstdlib>
#include <iostream>

void normalizeNumber(int input[]);
void doubleDigits(int input[]);

int main(int argc, char **argv){
    //calculate the sum of the digits in 2^1000
    
    int result[1000] = {2}; //guessing the result will be fewer than 500 digits
    
    //do 2^1000
    for(int i = 0; i < 999; i++){ //there is already a 2 in the array so we need 999 loops
        doubleDigits(result);
        normalizeNumber(result);
    }
    
    //sum digits
    int sum = 0;
    for(int i = 0; i < 500; i++){
        sum += result[i];
    }
    
    std::cout << sum << std::endl;
    
    return EXIT_SUCCESS;
}

void normalizeNumber(int input[]){
    for(int i = 0; i < 500; i++){
        while(input[i] > 9){
            input[i] -= 10;
            input[i+1] += 1;
        }
    }
}
void doubleDigits(int input[]){
    for(int i = 0; i < 500; i++){
        input[i] *= 2;
    }
}