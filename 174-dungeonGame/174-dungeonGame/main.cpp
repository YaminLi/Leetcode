//
//  main.cpp
//  174-dungeonGame
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon){
        if (dungeon.empty()) return 0;
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[m-1][n-1]=min(dungeon[m-1][n-1], 0);
        for (int i=n-2; i>=0; i--){
            dp[m-1][i] = min(dungeon[m-1][i]+dp[m-1][i+1], 0);
        }
        for (int i=m-2; i>=0; i--){
            dp[i][n-1] = min(dungeon[i][n-1]+dp[i+1][n-1], 0);
        }
        for (int i=m-2; i>=0; i--){
            for (int j=n-2; j>=0; j--){
                dp[i][j] = max(min(dungeon[i][j]+dp[i+1][j], 0), min(dungeon[i][j]+dp[i][j+1], 0));
            }
        }
        return abs(dp[0][0])+1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    Solution st;
    cout << st.calculateMinimumHP(dungeon) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
