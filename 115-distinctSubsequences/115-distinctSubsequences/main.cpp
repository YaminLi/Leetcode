//
//  main.cpp
//  115-distinctSubsequences
//
//  Created by Michael on 11/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numDinstinct(string s, string t){
        if (s.empty()) return 0;
        int m = s.size(), n = t.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for (int i=0; i<=m; i++)
            dp[i][0] = 1;
        for (int j=1; j<=n; j++)
            dp[0][j] = 0;
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.numDinstinct("rabbbit", "rabbit")<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
