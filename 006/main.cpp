#include <cstdlib>
#include <iostream>

int main(int argc, char **argv){
    long long sumOfSquares = 0;
    long long squareOfSum = 0;
    
    for(int i = 1; i <= 100; i++){
        sumOfSquares += i*i;
        squareOfSum += i;
    }
    squareOfSum *= squareOfSum;
    
    std::cout <<  squareOfSum - sumOfSquares << std::endl;
    
    return EXIT_SUCCESS;
}