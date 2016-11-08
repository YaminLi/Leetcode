//
//  main.cpp
//  63-uniquePaths2
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        if (obstacleGrid.empty()) {
            return 0;
        }
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 1));
        for (int i=m-1; i>=0; i--) {
            if (obstacleGrid[i][n-1] == 1) {
                for (int j=i; j>=0; j--) {
                    res[j][n-1] = 0;
                }
                break;
            }
        }
        for (int i=n-1; i>=0; i--) {
            if (obstacleGrid[m-1][i] == 1) {
                for (int j=i; j>=0; j--) {
                    res[m-1][j] = 0;
                }
                break;
            }
        }
        for (int i=m-2; i>=0; i--) {
            for (int j=n-2; j>=0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    res[i][j] = 0;
                    continue;
                }
                res[i][j] = res[i+1][j] + res[i][j+1];
            }
        }
        return res[0][0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
