//
//  main.cpp
//  36-validSudoku
//
//  Created by Michael on 10/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool isValidSudoku(vector<string>& board){
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] != '.') {
                    for (int k=j+1; k<board[0].size(); k++) {
                        if (board[i][k] == board[i][j])
                            return false;
                    }
                    for (int k=i+1; k<board.size(); k++) {
                        if (board[k][j] == board[i][j])
                            return false;
                    }
                    for (int k=i/3*3; k<i/3*3+3; k++) {
                        for (int m=j/3*3; m<j/3*3+3; m++) {
                            if (k != i && m != j && board[k][m] == board[i][j]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> a = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
    Solution st;
    if (st.isValidSudoku(a)) {
        std::cout << "Hello, World!\n";
    }
    
    return 0;
}
