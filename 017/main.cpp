#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <string>

int main(int argc, char **argv){
    
    std::unordered_map<int, std::string> numberWords;
    int ones = 0;
    int tens = 0;
    int hundreds = 0;
    int sum = 0;
    std::string numberWord = "";
    
    //populate base "number words"
    
    //ones place
    numberWords.insert(std::make_pair<int,std::string>(0,"")); //you never say zero
    numberWords.insert(std::make_pair<int,std::string>(1,"one"));
    numberWords.insert(std::make_pair<int,std::string>(2,"two"));
    numberWords.insert(std::make_pair<int,std::string>(3,"three"));
    numberWords.insert(std::make_pair<int,std::string>(4,"four"));
    numberWords.insert(std::make_pair<int,std::string>(5,"five"));
    numberWords.insert(std::make_pair<int,std::string>(6,"six"));
    numberWords.insert(std::make_pair<int,std::string>(7,"seven"));
    numberWords.insert(std::make_pair<int,std::string>(8,"eight"));
    numberWords.insert(std::make_pair<int,std::string>(9,"nine"));
    
    //tens place
    numberWords.insert(std::make_pair<int,std::string>(10,"ten"));
    numberWords.insert(std::make_pair<int,std::string>(20,"twenty"));
    numberWords.insert(std::make_pair<int,std::string>(30,"thirty"));
    numberWords.insert(std::make_pair<int,std::string>(40,"forty"));
    numberWords.insert(std::make_pair<int,std::string>(50,"fifty"));
    numberWords.insert(std::make_pair<int,std::string>(60,"sixty"));
    numberWords.insert(std::make_pair<int,std::string>(70,"seventy"));
    numberWords.insert(std::make_pair<int,std::string>(80,"eighty"));
    numberWords.insert(std::make_pair<int,std::string>(90,"ninety"));
    
    //tens/ones hybrids
    numberWords.insert(std::make_pair<int,std::string>(11,"eleven"));
    numberWords.insert(std::make_pair<int,std::string>(12,"twelve"));
    numberWords.insert(std::make_pair<int,std::string>(13,"thirteen"));
    numberWords.insert(std::make_pair<int,std::string>(14,"fourteen"));
    numberWords.insert(std::make_pair<int,std::string>(15,"fifteen"));
    numberWords.insert(std::make_pair<int,std::string>(16,"sixteen"));
    numberWords.insert(std::make_pair<int,std::string>(17,"seventeen"));
    numberWords.insert(std::make_pair<int,std::string>(18,"eighteen"));
    numberWords.insert(std::make_pair<int,std::string>(19,"nineteen"));
    
    //hundreds
    numberWords.insert(std::make_pair<int,std::string>(100,"onehundred"));
    numberWords.insert(std::make_pair<int,std::string>(200,"twohundred"));
    numberWords.insert(std::make_pair<int,std::string>(300,"threehundred"));
    numberWords.insert(std::make_pair<int,std::string>(400,"fourhundred"));
    numberWords.insert(std::make_pair<int,std::string>(500,"fivehundred"));
    numberWords.insert(std::make_pair<int,std::string>(600,"sixhundred"));
    numberWords.insert(std::make_pair<int,std::string>(700,"sevenhundred"));
    numberWords.insert(std::make_pair<int,std::string>(800,"eighthundred"));
    numberWords.insert(std::make_pair<int,std::string>(900,"ninehundred"));
    
    //special case 1000
    numberWords.insert(std::make_pair<int,std::string>(1000,"onethousand"));
    
    //construct remaining "number words"
    for(int i = 1; i <= 1000; i++){
        if(numberWords.count(i) > 0){ //don't reinsert an existing "number word"
            continue;
        }
        numberWord = "";
        ones = i % 10;
        tens = i % 100 - ones;
        hundreds = i % 1000 - tens - ones;
        if(i < 100){
            numberWord += numberWords.at(tens); // + " ";
            numberWord += numberWords.at(ones);
        } else if(tens != 0){ //need hybrid tens/ones
            numberWord += numberWords.at(hundreds) + "and"; // + " and ";
            numberWord += numberWords.at(ones+ tens);
        } else {
            numberWord += numberWords.at(hundreds) + "and"; // + " and ";
            numberWord += numberWords.at(tens); // + (tens == 0 ? "" : " ");
            numberWord += numberWords.at(ones);
        }
        numberWords.insert(std::make_pair<int,std::string>(i,numberWord));
        //std::cout << i << " " << numberWord << std::endl;
    }
    
    //sum the number of letters
    for(int i = 1; i <= 1000; i++){
        sum += numberWords.at(i).length();
        //std::cout << sum << ": " << numberWords.at(i) << std::endl;
    }
    
    std::cout << sum << std::endl;
    
    return EXIT_SUCCESS;
}