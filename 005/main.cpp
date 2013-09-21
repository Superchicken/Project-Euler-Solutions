#include <cstdlib>
#include <iostream>

int main(int argc, char **argv){
    long long number = 2520; //copied from problem
    bool done =  false;
    
    while(!done){
        for(int i = 2; i <= 20; i++){
            if(number % i != 0){
                number += 2; //skip odd numbers
                break;
            }
            if(i == 20){
                done = true;
            }
        }
    }
    
    std::cout << number << std::endl;
    
    return EXIT_SUCCESS;
}