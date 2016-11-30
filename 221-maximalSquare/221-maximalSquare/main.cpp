//
//  main.cpp
//  221-maximalSquare
//
//  Created by Michael on 11/29/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maximalSquare(vector<vector<char>>& matrix){
        // 当我们判断以某个点为正方形右下角时最大的正方形时，那它的上方，左方和左上方三个点也一定是某个正方形的右下角，否则该点为右下角的正方形最大就是它自己了。这是定性的判断，那具体的最大正方形边长呢？我们知道，该点为右下角的正方形的最大边长，最多比它的上方，左方和左上方为右下角的正方形的边长多1，最好的情况是是它的上方，左方和左上方为右下角的正方形的大小都一样的，这样加上该点就可以构成一个更大的正方形。但如果它的上方，左方和左上方为右下角的正方形的大小不一样，合起来就会缺了某个角落，这时候只能取那三个正方形中最小的正方形的边长加1了
        if (matrix.empty()) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        int maxSize = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i=0; i<m; i++){
            if (matrix[i][0] == '1'){
                dp[i][0] = 1;
                maxSize = 1;
            }
        }
        
        for (int j=0; j<n; j++) {
            if (matrix[0][j] == '1'){
                dp[0][j] = 1;
                maxSize = 1;
            }
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (matrix[i][j] == '1'){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }
        return maxSize*maxSize;
    }
    
    int maximalSquare1(vector<vector<char>>& matrix){
        int maxSize = 0;
        if (matrix.empty()) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == '1'){
                    for (int len=1; i+len-1<m && j+len-1<n; len++){
                        if (isSquare(matrix, i, j, len)){
                            maxSize = max(maxSize, len);
                        }
                        else
                            break;
                    }
                }
            }
        }
        return maxSize*maxSize;
    }
    
private:
    bool isSquare(vector<vector<char>>& matrix, int row, int col, int len){
        for (int i=row; i<row+len; i++){
            for (int j=col; j<col+len; j++){
                if (matrix[i][j] != '1')
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    Solution st;
    cout << st.maximalSquare(matrix)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
