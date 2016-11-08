//
//  main.cpp
//  64-minimumPathSum
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int>>& grid){
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        for (int i=m-2; i>=0; i--) {
            grid[i][n-1] += grid[i+1][n-1];
        }
        for (int i=n-2; i>=0; i--) {
            grid[m-1][i] += grid[m-1][i+1];
        }
        for (int i=m-2; i>=0; i--) {
            for (int j=n-2; j>=0; j--) {
                grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
