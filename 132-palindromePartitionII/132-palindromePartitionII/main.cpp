//
//  main.cpp
//  132-palindromePartitionII
//
//  Created by Michael on 11/9/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minCut(string s){
        int n=s.size();
        if (n<=1) return 0;
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i=n-1; i>=0; i--){
            for (int j=i; j<n; j++){
                if ((j<i+2 || isPalin[i+1][j-1]) && s[i] == s[j])
                    isPalin[i][j] = true;
            }
        }
        
        vector<int> dp(n+1, INT_MAX);
        dp[n] = -1;
        for (int i=n-1; i>=0; i--){
            for (int j=i+1; j<=n; j++){
                if (isPalin[i][j-1]){
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[0];
    }
    
    int minCut1(string s){
        int n = s.size();
        if (n==0 || n==1) return 0;
        int minRes = INT_MAX;
        for (int len = n; len>=1; len--){
            string subs = s.substr(0, len);
            if (isPalin(subs)){
                if (len == n) return 0;
                minRes = min(minRes, minCut(s.substr(len)));
            }
        }
        return 1+minRes;
    }
    
private:
    bool isPalin(string s){
        int left=0;
        int right=s.size()-1;
        while (left <= right){
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.minCut("aab") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
