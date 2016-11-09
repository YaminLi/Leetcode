//
//  main.cpp
//  120-Triangle
//
//  Created by Michael on 11/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minimumTotal(vector<vector<int>>& triangle){
        if (triangle.empty()) return 0;
        int m = triangle.size();
        for (int i=1; i<m; i++){
            int n = triangle[i].size();
            triangle[i][0] += triangle[i-1][0];
            for (int j=1; j<n-1; j++){
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
            triangle[i][n-1] += triangle[i-1][n-2];
        }
        int res=INT_MAX;
        for (int i=0; i<triangle[m-1].size(); i++){
            if (triangle[m-1][i] < res)
                res = triangle[m-1][i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int > > a = {{2}, {3, 4}, {6,5,7},{4,1,8,3}};
    Solution st;
    cout << st.minimumTotal(a)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
