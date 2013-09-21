#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>

std::string ReverseString(std::string input);
std::stringstream converter;

int main(int argc, char **argv){
    int largest = 0;
    for(int i = 100; i <= 999; i++){
        for(int j = 100; j <= 999; j++){
            converter << i*j;
            
            if(strcmp(ReverseString(converter.str()).c_str(), converter.str().c_str()) == 0){
                largest = std::max(largest, i*j);
            }
            converter.str(std::string());
        }
    }
    std::cout << largest << std::endl;
    
    return EXIT_SUCCESS;
}

std::string ReverseString(std::string input){
    std::string output = "";
    for(int i = input.length() - 1; i >= 0; i--){
        output += input[i];
    }
    return output;
}