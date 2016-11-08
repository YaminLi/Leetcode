//
//  main.cpp
//  54-spiralMatrix
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> res;
        if((matrix.empty()) || matrix.size() == 0) return res;
        int m = matrix.size(), n = matrix[0].size();
        int numLev = (min(m, n)-1)/2+1;
        for(int i = 0; i<numLev; i++){
            for(int j=i; j< n-i; j++){
                res.push_back(matrix[i][j]);
            }
            for(int j=i+1; j<m-i; j++){
                res.push_back(matrix[j][n-i-1]);
            }
            if(i != m-i-1)
                for(int j=n-i-2; j>=i; j--){
                    res.push_back(matrix[m-i-1][j]);
                }
            if(i != n-i-1)
                for(int j=m-i-2; j>i; j--){
                    res.push_back(matrix[j][i]);
                }
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a={{1,2,3},{4,5,6},{7,8,9}};
    Solution st;
    vector<int> res = st.spiralOrder(a);
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
