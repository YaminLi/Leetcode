//
//  main.cpp
//  200-numberOfIslands
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numIslands(vector<vector<char> >& grid){
        int cnt=0;
        int m=grid.size();
        if (m==0) return cnt;
        for (int i=0; i<m; i++){
            for (int j=0; j<grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    cnt++;
                    helper(grid, i, j);
                }
            }
        }
        return cnt;
    }
    
private:
    void helper(vector<vector<char> >& grid, int row, int col){
        grid[row][col] = '0';
        if (row > 0 && grid[row-1][col] == '1')
            helper(grid, row-1, col);
        if (row < grid.size()-1 && grid[row+1][col] == '1')
            helper(grid, row+1, col);
        if (col > 0 && grid[row][col-1] == '1')
            helper(grid, row, col-1);
        if (col < grid[0].size()-1 && grid[row][col+1] == '1')
            helper(grid, row, col+1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    Solution st;
    cout << st.numIslands(grid)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
