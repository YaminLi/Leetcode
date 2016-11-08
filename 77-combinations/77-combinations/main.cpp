//
//  main.cpp
//  77-combinations
//
//  Created by Michael on 10/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinations(int n, int k){
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, 1, n, k);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& tmp, int begin, int n, int k){
        if (k==0) {
            res.push_back(tmp);
            return;
        }
        for (int i=begin; i<=n; i++) {
            tmp.push_back(i);
            helper(res, tmp, i+1, n, k-1);
            tmp.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<vector<int>> a = st.combinations(4, 2);
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
