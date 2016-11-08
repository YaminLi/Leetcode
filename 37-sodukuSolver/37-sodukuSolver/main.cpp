//
//  main.cpp
//  37-sodukuSolver
//
//  Created by Michael on 10/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool solveSodoku(vector<vector<char>>& board){
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (int k=1; k<=9; k++) {
                        board[i][j] = k+'0';
                        if (isValid(board, i, j) && solveSodoku(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool isValid(vector<vector<char>>& board, int row, int col){
        for(int i=0; i<board.size(); i++){
            if (i!=row && board[i][col] == board[row][col])
                return false;
        }
        
        for (int j=0; j<board[0].size(); j++) {
            if (j!=col && board[row][j] == board[row][col])
                return false;
        }
        
        for (int i=row/3*3; i<row/3*3+3; i++) {
            for (int j=col/3*3; j<col/3*3+3; j++) {
                if (i!= row && j!=col && board[i][j] == board[row][col])
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
