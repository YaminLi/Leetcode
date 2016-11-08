//
//  main.cpp
//  74-searchA2DMatrix
//
//  Created by Michael on 10/23/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (matrix[mid/n][mid%n] ==  target) {
                return true;
            }
            else if (matrix[mid/n][mid%n] < target)
                left = mid+1;
            else
                right= mid-1;
        }
        return false;
    }
    
    bool searchMatrix1(vector<vector<int>>& matrix, int target){
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m-1;
        while (left < right && matrix[right][0] > target) {
            int mid = (right+left+1)/2;
            if (matrix[mid][0] == target) {
                return true;
            }
            else if(matrix[mid][0] > target)
                right = mid-1;
            else
                left = mid;
        }
        int row = left;
        left = 0;
        right = n-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (matrix[row][mid] == target) {
                return true;
            }
            else if (matrix[row][mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        return false;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {
        {1},   {3}
    };
    Solution st;
    if (st.searchMatrix(a, 3)) {
        std::cout << "Hello, World!\n";
    }
    return 0;
}
