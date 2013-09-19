#include <cstdlib>
#include <iostream>

int main(int argc, char **argv){
    long long input = 600851475143;
    long long factor = 2;
    
    while(factor * factor < input){
        while(input % factor == 0){
            //seperate newly found factor from largest factor
            input /= factor;
        }
        factor++;
    }
    
    std::cout << input << std::endl;
    
    return EXIT_SUCCESS;
}
