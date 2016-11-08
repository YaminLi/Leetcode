//
//  main.cpp
//  51-nQueens
//
//  Created by Michael on 10/18/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        helper(res, tmp, 0, n);
        return res;
    }

private:
    void helper(vector<vector<string>>& res, vector<string>& tmp, int row, int n){
        if (row == n) {
            res.push_back(tmp);
            return;
        }
        for (int i=0; i<n; i++) {
            if (isValid(tmp, row, i)) {
                tmp[row][i] = 'Q';
                helper(res, tmp, row+1, n);
                tmp[row][i] = '.';
            }
        }
    }
    
    
    bool isValid(vector<string> tmp, int row, int col){
        for (int i=0; i<tmp.size(); i++) {
            if (i != row && tmp[i][col] == 'Q') {
                return false;
            }
        }
        
        for (int j=0; j<tmp.size(); j++) {
            if (j != col && tmp[row][j] == 'Q') {
                return false;
            }
        }
        
        for (int i=0; i<tmp.size(); i++) {
            for (int j=0; j<tmp.size(); j++) {
                if (i != row && j!= col && ((i+j) == (row+col) || (i-j) == (row-col)) && tmp[i][j] == 'Q') {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<vector<string>> res = st.solveNQueens(4);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
