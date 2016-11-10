//
//  main.cpp
//  130-surroundRegions
//
//  Created by Michael on 11/9/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void solve(vector<vector<char>>& board){
        int row = board.size();
        if (!row)
            return;
        int col = board[0].size();
        for (int i=0; i<row; i++){
            helper(board, i, 0, row, col);
            if (col > 1)
                helper(board, i, col-1, row, col);
        }
        for (int j=1; j<col-1; j++){
            helper(board, 0, j, row, col);
            if (row > 1)
                helper(board, row-1, j, row, col);
        }
        
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (board[i][j] == '1')
                    board[i][j] = 'O';
    }
    
private:
    void helper(vector<vector<char>>& board, int i, int j, int row, int col){
        if (board[i][j] == 'O'){
            board[i][j] = '1';
            if (i>1) helper(board, i-1, j, row, col);
            if (j>1) helper(board, i, j-1, row, col);
            if (i<row-1) helper(board, i+1, j, row, col);
            if (j<col-1) helper(board, i, j+1, row, col);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char> > a = {{'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};
    Solution st;
    st.solve(a);
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<a[i].size(); j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
