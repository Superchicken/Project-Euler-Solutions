#include <cstdlib>
#include <iostream>
#include <cmath>

bool Prime(int input);

int main(int argc, char **argv){
    long long sum = 0; 
    
    for(int i = 2; i < 2000000; i++){ 
        if(Prime(i)){ 
            sum += i; 
        } 
    } 
    std::cout << "sum of primes: " << sum << std::endl; 
    
    return EXIT_SUCCESS;
}

bool Prime(int input){
    for(int i = 2; i <= sqrt(input); i++){
        if(input % i == 0){
            return false;
        }
    }
    return true;
}