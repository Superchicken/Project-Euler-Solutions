#include <cstdlib>
#include <iostream>

int main(int argc, char **argv){
    
    int sum = 0;
    
    for(int i = 1; i < 1000; i++){
        if(i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    
    std::cout << sum << std::endl;
    
    return EXIT_SUCCESS;
}