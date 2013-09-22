#include <sstream> 
#include <iostream> 
using namespace std; 
  
//Input: a 5-digit positive int 
//Output: the product of the 5 digits 
int productOfDigits(int input); 
int charToInt(char input); 
int stringToInt(string input); 
string intToString(int input); 
  
int main(int argc, char **argv){ 
    string data = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"; 
    int greatestProduct = 0; 
    //grab all combos of 5 consecutive digits 
    for(int x = 0; x < data.length() - 4; x++){ 
        int product = productOfDigits(stringToInt(data.substr(x, 5))); 
        //cout << "product of " << data.substr(x, 5) << " is: " << product << endl; 
        if(product > greatestProduct){ 
            greatestProduct = product; 
        } 
    }  
    cout << "Greatest product: " << greatestProduct << endl; 
} 
  
int productOfDigits(int input){ 
    string digits = intToString(input); 
    return charToInt(digits[0])*charToInt(digits[1])*charToInt(digits[2])*charToInt(digits[3])*charToInt(digits[4]); 
} 
  
//Input: a char containing a digit 0-9 
//Output: int representation of input 
int charToInt(char input){ 
    stringstream buffer; 
    int output = 0; 
    buffer << input; 
    buffer >> output; 
    return output; 
} 
//Input: a string containing only digits 0-9 
//Output: int representation of input 
int stringToInt(string input){ 
    stringstream buffer; 
    int output = 0; 
    buffer << input; 
    buffer >> output; 
    return output; 
} 
//Input: a non-zero positive int 
//Output: input stored in a string 
string intToString(int input){ 
    stringstream buffer; 
    string output = ""; 
    buffer << input; 
    buffer >> output; 
    return output; 
} 