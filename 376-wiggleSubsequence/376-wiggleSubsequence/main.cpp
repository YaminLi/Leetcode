//
//  main.cpp
//  376-wiggleSubsequence
//
//  Created by Michael on 1/15/17.
//  Copyright © 2017 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int n=nums.size();
    if (n<=1) return n;
    vector<int> dp(n, 1), diff(n, 0);
    int res=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (diff[j]==0 && nums[i] != nums[j]){
                if (dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    diff[i] = nums[i]-nums[j];
                }
            }
            else if ((diff[j]<0 && nums[i]>nums[j]) || (diff[j]>0 && nums[i]<nums[j])){
                if (dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    diff[i] = nums[i]-nums[j];
                }
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << wiggleMaxLength(nums) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
