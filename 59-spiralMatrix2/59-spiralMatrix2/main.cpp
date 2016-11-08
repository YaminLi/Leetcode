//
//  main.cpp
//  59-spiralMatrix2
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        int numLev = (n+1)/2;
        int lev = 0;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        while (lev < numLev) {
            for (int i=lev; i<n-lev; i++) {
                res[lev][i] = num;
                num++;
            }
            for (int i=lev+1; i<n-lev; i++) {
                res[i][n-lev-1] = num;
                num++;
            }
            for (int i=n-lev-2; i>=lev; i--) {
                res[n-lev-1][i] = num;
                num++;
            }
            for (int i=n-lev-2; i>lev; i--) {
                res[i][lev] = num;
                num++;
            }
            lev++;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution   st;
    vector<vector<int>> res= st.generateMatrix(3);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
//    std::cout << "Hello, World!\n";
    return 0;
}
