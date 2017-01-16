//
//  main.cpp
//  375-guessNumberHigherOrLowerII
//
//  Created by Michael on 1/15/17.
//  Copyright © 2017 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int getMoneyAmount(int n) {
    // dp[i][j]表示从数字i到j之间猜中任意一个数字最少需要花费的钱数
    vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
    for (int i=1; i<=n; i++){
        dp[i][i] = 0;
        if (i+1<=n){
            dp[i][i+1]=i;
        }
    }
    
    for (int len=3; len<=n; ++len){
        for (int left=1; left+len-1<=n; ++left){
            int right = left+len-1;
            for (int mid=left+1; mid<right; ++mid){
                dp[left][right] = min(dp[left][right], mid+max(dp[left][mid-1], dp[mid+1][right]));
            }
        }
    }
    return dp[1][n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << getMoneyAmount(5) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
