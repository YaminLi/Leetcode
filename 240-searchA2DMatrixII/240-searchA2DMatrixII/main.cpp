//
//  main.cpp
//  240-searchA2DMatrixII
//
//  Created by Michael on 12/13/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if (matrix.empty()) return false;
        int m=matrix.size(), n=matrix[0].size();
        int left=0, right=m-1;
        while (left <= right){
            int mid=left+(right-left)/2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        int row = left;
        for (int i=0; i<row; i++){
            left = 0, right=n-1;
            while (left<=right){
                int mid=left+(right-left)/2;
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] < target)
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return false;
    }
    
    bool searchMatrix1(vector<vector<int>>& matrix, int target){
        if (matrix.empty()) return false;
        int m=matrix.size(), n=matrix[0].size();
        int row=0, col=n-1;
        while (row<m && col>=0){
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix = {
        {-1, 3}
    };
    Solution st;
    if (st.searchMatrix(matrix, 3))
        std::cout << "Hello, World!\n";
    return 0;
}
