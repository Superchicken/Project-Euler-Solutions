#include <cstdlib>
#include <iostream>
#include <cmath>

int factors(int input);

int main(int argc, char **argv){
    int triangleCounter = 1;
    int triangleValue = 1;
    int factor = 0;
 
    while(factor <= 500){
        factor = factors(triangleValue);
        std::cout << triangleValue << ": has " << factor << " factors" << std::endl;
        triangleCounter++;
        triangleValue += triangleCounter;
    }
 
    std::cout << triangleValue << std::endl;
    
    return EXIT_SUCCESS;
}

//returns how many factors the input has
int factors(int input){
    int output = 0;
 
    for(int i = 1; i <= sqrt(input); i++){
        if(input % i == 0){
                output += 2;
        }
    }
    return output;  
}