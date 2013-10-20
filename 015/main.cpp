#include <cstdlib>
#include <iostream>

int main(int argc, char **argv){
    //elegant solution
    // 40!
    //------  =  137 846 528 820
    //20!20!
    
    //not so elegant solution
    long long grid[21][21] = {{0}}; //2x2 grid has 3x3 vertices!
    
    //set "edges" to one
    for(long long i = 0; i <= 20; i++){
        grid[i][0] = 1;
        grid[0][i] = 1;
    }
    
    //calculate the number of paths
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= 20; j++){
            grid[i][j] = grid[i][j-1] + grid[i-1][j];
        }
    }
        
    std::cout << grid[20][20] << std::endl;
    
    return EXIT_SUCCESS;
}
