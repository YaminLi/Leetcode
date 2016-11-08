//
//  main.cpp
//  62-uniquePaths
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int uniquePaths(int m, int n){
        vector<vector<int>> res(m, vector<int>(n, 1));
        for (int i=m-2; i>=0; i--) {
            for (int j=n-2; j>=0; j--) {
                res[i][j] = res[i+1][j] + res[i][j+1];
            }
        }
        return res[0][0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution st;
    cout << st.uniquePaths(3, 7) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
