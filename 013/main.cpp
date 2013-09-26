#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class BigInt {
    public:
        BigInt();
        BigInt(std::string initalValue);
        int size() const;
        std::string toString() const;
        BigInt operator+(const BigInt &summand);
    private:
        std::string data;
};

int main(int argc, char **argv){
    
    std::vector<std::string> input;
    std::ifstream inputFile("input");
    std::string temp = "";
    
    while(inputFile >> temp){
        input.push_back(temp);
    }
    
    BigInt result;
    int counter = 0;
    for(std::vector<std::string>::iterator it = input.begin(); it != input.end(); ++it){
        result = result + BigInt(*it);
        std::cout << *it << " " << ++counter << std::endl;
        //if(counter == 20) break;
        //std::cout << "summands: " << ++counter << std::endl;
    }
    
    std::cout << result.toString() << std::endl;
    
    return EXIT_SUCCESS;
}

BigInt::BigInt(){
    //TODO
}
BigInt::BigInt(std::string initialValue){
    data = initialValue;
}
int BigInt::size() const {
    return data.length();
}
std::string BigInt::toString() const {
    return data;
}
BigInt BigInt::operator+(const BigInt &summand){
    int size = std::max(summand.size(), this->size());
    std::string a(this->toString());
    std::string b(summand.toString());
    
    //pad smaller summand to be the same length as larger summand
    if(a.size() != b.size()){
        if(a.size() < b.size()){
            while(a.size() != b.size()){
                a = "0" + a;
            }
        }
        if(a.size() > b.size()){
            while(a.size() != b.size()){
                b = "0" + b;
            }
        }
    }
    
    long long carry = 0;
    long long sum = 0;
    std::string result = "";
    for(int i = size - 1; i >= 0; --i){
        sum = (int)(a.at(i) - '0') + (int)(b.at(i) - '0') + carry;
        carry = 0;
        
        while(sum > 9){
            sum = sum - 10;
            ++carry;
        }
        
        //std::cout << a.at(i) << " + " << b.at(i) << " = " << sum;
        //std::cout << " carry " << carry << std::endl;
        
        result = std::to_string(sum) + result; //to_string(int) is not implemented :/
        
        //special case: we need to extend the number
        if(i == 0 && carry > 0){
            result = std::to_string(carry) + result; //to_string(int) is not implemented :/
        }
    }
    return BigInt(result);
}




