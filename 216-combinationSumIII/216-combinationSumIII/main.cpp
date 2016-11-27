//
//  main.cpp
//  216-combinationSumIII
//
//  Created by Michael on 11/26/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, 1, 0, 0, k, n);
        return res;
    }
    
private:
    void helper(vector<vector<int>>& res, vector<int>& tmp, int begin, int sum, int cnt, int k, int n){
        if (cnt == k && sum == n){
            res.push_back(tmp);
            return;
        }
        if (cnt > k || (cnt == k && sum != n)){
            return;
        }
        for (int i=begin; i<=9; i++){
            tmp.push_back(i);
            sum += i;
            helper(res, tmp, i+1, sum, cnt+1, k, n);
            sum -= i;
            tmp.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<vector<int>> res = st.combinationSum3(3, 9);
    for (int i=0; i<res.size(); i++){
        for (int j=0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
