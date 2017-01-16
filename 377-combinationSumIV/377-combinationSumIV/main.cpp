//
//  main.cpp
//  377-combinationSumIV
//
//  Created by Michael on 1/15/17.
//  Copyright © 2017 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& nums, int sum, int target, int& cnt){
    if (sum==target){
        cnt++;
        return;
    }
    if (sum > target) return;
    for (int i=0; i<nums.size(); i++){
        helper(nums, sum+nums[i], target, cnt);
    }
}

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= target; ++i) {
        for (auto a : nums) {
            if (i < a) break;
            dp[i] += dp[i - a];
        }
    }
    return dp.back();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {3,33,333};
    cout << combinationSum4(nums, 10000)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
