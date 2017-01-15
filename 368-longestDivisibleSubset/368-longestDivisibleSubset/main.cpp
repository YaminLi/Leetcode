//
//  main.cpp
//  368-longestDivisibleSubset
//
//  Created by Michael on 1/15/17.
//  Copyright © 2017 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    if (nums.empty()) return res;
    sort(nums.begin(), nums.end());
    int n=nums.size();
    vector<int> dp(n, 0), parent(n, 0);
    int mx=0, mxIdx=0;
    for (int i=0; i<n; i++){
        for (int j=i; j>=0; j--){
            if (nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
                parent[i] = j;
                if (mx<dp[i]){
                    mx = dp[i];
                    mxIdx = i;
                }
            }
        }
    }
    
    for (int i=0; i<mx; i++){
        res.push_back(nums[mxIdx]);
        mxIdx = parent[mxIdx];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3};
    vector<int> res = largestDivisibleSubset(nums);
    for (auto i:res){
        cout << i << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
