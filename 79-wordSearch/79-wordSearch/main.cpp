//
//  main.cpp
//  79-wordSearch
//
//  Created by Michael on 10/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool exist(vector<vector<char>>& board, string word){
        if (board.empty()) {
            return false;
        }
        if (word.empty()) {
            return true;
        }
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (helper(board, word, used, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool helper(vector<vector<char>>& board, string word, vector<vector<bool>>& used, int row, int col, int idx){
        if (idx == word.size()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col<0 || col >= board[0].size() || used[row][col] || board[row][col] != word[idx]) {
            return false;
        }
        used[row][col] = true;
        bool res = helper(board, word, used, row-1, col, idx+1)
                || helper(board, word, used, row+1, col, idx+1)
                || helper(board, word, used, row, col-1, idx+1)
                || helper(board, word, used, row, col+1, idx+1);
        used[row][col] = false;

        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char>> a = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    Solution st;
    if (st.exist(a, "SEE")) {
        std::cout << "Hello, World!\n";

    }
    return 0;
}
