//
//  main.cpp
//  72-editDistance
//
//  Created by Michael on 10/23/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minDistance(string word1, string word2){
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> res(m+1, vector<int>(n+1, 0));
        for (int i=0; i<n+1; i++) {
            res[0][i] = i;
        }
        for (int i=0; i<m+1; i++) {
            res[i][0] = i;
        }
        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                if (word1[i-1] != word2[j-1]) {
                    res[i-1][j-1]++;
                }
                res[i][j]= min(res[i-1][j-1], min(res[i-1][j]+1, res[i][j-1]+1));
            }
        }
        return res[m][n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.minDistance("Hello", "world");
//    std::cout << "Hello, World!\n";
    return 0;
}
