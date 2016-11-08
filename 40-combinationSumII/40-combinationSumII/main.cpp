//
//  main.cpp
//  40-combinationSumII
//
//  Created by Michael on 10/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target){
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
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
                if (i>begin && nums[i] == nums[i-1]) {
                    continue;
                }
                tmp.push_back(nums[i]);
                helper(nums, res, tmp, i+1, target-nums[i]);
                tmp.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a={10, 1,2,7,6, 1, 5};
    Solution st;
    vector<vector<int>> res=st.combinationSum2(a, 8);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
//    cout << st.combinationSum2(a, 8).size()<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
