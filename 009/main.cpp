#include <iostream> 
using namespace std; 
  
bool isTriplet(int a, int b, int c); 
  
int main(int argc, char **argv){ 
    for(int c = 3; c < 1000; c++){ //arbitrary max for C 
        for(int b = 1; b < c; b++){ 
            for(int a = 1; a < b; a++){ 
                if(isTriplet(a, b, c)){ 
                //  cout << "triplet: " << a << b << c << endl; 
                    if(a + b + c == 1000){ 
                        cout << "we have a winner: " << a << " "
                                         << b << " "
                                         << c << " "
                                         << endl; 
                        cout << "product: " << a*b*c << endl;
                    } 
                } 
            } 
        } 
    } 
} 
  
//Input: 3 nonzero positive ints 
//Output: true if a triple, false otherwise 
bool isTriplet(int a, int b, int c){ 
    if(a < b || b < c){ 
        if(a*a + b*b == c*c){ 
            //a < b < c AND 
            //a^2+ b^2 = c^2 
            return true; 
        } 
    } 
    return false; 
} 