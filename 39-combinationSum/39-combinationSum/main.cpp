//
//  main.cpp
//  39-combinationSum
//
//  Created by Michael on 10/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target){
        vector<vector<int>> res;
        vector<int> tmp;
        helper(nums, res, tmp, 0, target);
        return res;
    }
    
private:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, int begin, int target){
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i=begin; i<nums.size(); i++) {
            if (nums[i] <= target) {
                tmp.push_back(nums[i]);
                helper(nums, res, tmp, i, target-nums[i]);
                tmp.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {2, 3, 6, 7};
    Solution st;
    cout << st.combinationSum(a, 7)[1].size()<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
