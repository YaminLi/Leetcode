//
//  main.cpp
//  73-setMatrixZeros
//
//  Created by Michael on 10/23/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void setZeros(vector<vector<int>>& matrix){
        int col0 = 0;
        for (int i=0; i<matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                col0 = 1;
            }
            for (int j=1; j<matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i=matrix.size()-1; i>=0; i--) {
            for (int j=1; j<matrix[i].size(); j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a={{1,1,1},{0,1,2}};
    Solution st;
    st.setZeros(a);
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
