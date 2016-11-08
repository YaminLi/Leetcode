//
//  main.cpp
//  46-permutations
//
//  Created by Michael on 10/17/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        helper(res, tmp, used, nums);
        return res;
    }
    
private:
    void helper1(vector<vector<int>>& res, int begin, vector<int>& nums){
        if (begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i=begin; i<nums.size(); i++) {
            swap(nums[i], nums[begin]);
            helper1(res, begin+1, nums);
            swap(nums[i], nums[begin]);
        }
    }
    
    void helper(vector<vector<int>>& res, vector<int>&tmp, vector<bool>& used, vector<int>& nums){
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
        }
        for (int i=0; i<nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            tmp.push_back(nums[i]);
            used[i] = true;
            helper(res, tmp, used, nums);
            tmp.pop_back();
            used[i] = false;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A = {1, 2, 3};
    Solution st;
    vector<vector<int>> res;
    res = st.permute(A);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
