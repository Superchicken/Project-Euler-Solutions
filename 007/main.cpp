#include <cstdlib>
#include <iostream>
#include <cmath>

bool Prime(int input);

int main(int argc, char **argv){
    int counter = 0;
    int value = 1;

    while(counter < 10001){
        value++;
        if(Prime(value)){
            counter++;
        }
    }
    std::cout << value << std::endl;
    
    return EXIT_SUCCESS;
}

bool Prime(int input){
    for(int i = 2; i < input; i++){
        if(input % i == 0){
            return false;
        }
    }
    return true;
}