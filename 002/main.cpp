#include <cstdlib>
#include <iostream>

int main(int argc, char **argv){
    int current = 2;
    int previous = 1;
    int temp = 0;
    int sum = 0;
    
    while(current <= 4000000){
        if(current % 2 == 0)
            sum += current;
            
        //update sequence
        temp = previous;
        previous = current;
        current += temp;
    }
    
    std::cout << sum << std::endl;
    
    return EXIT_SUCCESS;
}