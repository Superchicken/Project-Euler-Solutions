#include <cstdlib>
#include <iostream>
#include <unordered_map>

long long chainLength(long long input, std::unordered_map<long long, long long> &chainCache);

int main(int argc, char **argv){
    long long maxChainLength = 0;
    int term = 0;
    std::unordered_map<long long, long long> chainList;
    
    for(int i = 1; i < 1000000; i++){
        if(maxChainLength < chainLength(i, chainList)){
            term = i;
        }
        //calculating the same chain length again should be very fast
        maxChainLength = std::max(maxChainLength, chainLength(i, chainList));
    }
    
    /*std::cout << "Cache Contents" << std::endl;
    for(std::unordered_map<long long, long long>::iterator it = chainList.begin(); it != chainList.end(); ++it){
        std::cout << (*it).first << "->" << (*it).second << std::endl;
    }*/
    
    std::cout << maxChainLength << " " << term << std::endl;

    return EXIT_SUCCESS;
}

long long chainLength(long long input, std::unordered_map<long long, long long> &chainCache){
    long long length = 1;
    long long term = input;
    while(term != 1){
        if(chainCache.count(term) > 0){
            length += chainCache.at(term) - 1;
            break;
        }
        if(term % 2 == 0){     //even
            term = term / 2;
            ++length;
        } else {                //odd
            term = term * 3 + 1;
            ++length;
        }
    }
    chainCache.insert(std::make_pair<long long,long long>(input,length));
    //TODO: insert all terms from chain (not just the first one)
    return length;
}