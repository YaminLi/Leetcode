//
//  main.cpp
//  118-Pascal'sTriangle
//
//  Created by Michael on 11/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> res;
        if (numRows <= 0) return res;
        res.push_back(*new vector<int>{1});
        for (int i=2; i<=numRows; i++){
            vector<int> tmp(i);
            tmp[0] = 1;
            for (int j=1; j<i-1; j++){
                tmp[j] = res[i-2][j-1]+res[i-2][j];
            }
            tmp[i-1] = 1;
            res.push_back(tmp);
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<vector<int>> res = st.generate(5);
    for (int i=0; i<res.size(); i++){
        for (int j=0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
