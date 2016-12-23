//
//  main.cpp
//  312-burstBallons
//
//  Created by Michael on 12/22/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int>& nums) {
    int n=nums.size();
    if (n == 0) return 0;
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    for(int len=1; len<=n; len++){
        for (int left=1; left<=n-len+1; left++){
            int right = left+len-1;
            for (int k=left; k<=right; k++){
                dp[left][right] = max(dp[left][right], dp[left][k-1] + nums[left-1]*nums[k]*nums[right+1] + dp[k+1][right]);
            }
        }
    }
    return dp[1][n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums= {3, 1, 5, 8};
    cout << maxCoins(nums) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
