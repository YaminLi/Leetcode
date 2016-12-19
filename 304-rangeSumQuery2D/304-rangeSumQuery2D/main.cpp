//
//  main.cpp
//  304-rangeSumQuery2D
//
//  Created by Michael on 12/18/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sum;
    
public:
    NumMatrix(vector<vector<int>> &matrix): sum(matrix) {
        for (int i=1; i<matrix.size(); i++)
            sum[i][0] = sum[i-1][0]+matrix[i][0];
        
        for (int i=1; !matrix.empty() && i<matrix[0].size(); i++)
            sum[0][i] = sum[0][i-1]+matrix[0][i];
        
        for (int i=1; i<matrix.size(); i++){
            for (int j=1; j<matrix[i].size(); j++){
                sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1==0 && col1==0) return sum[row2][col2];
        if (row1==0) return sum[row2][col2]-sum[row2][col1-1];
        if (col1==0) return sum[row2][col2]-sum[row1-1][col2];
        return sum[row2][col2]-sum[row2][col1-1]-sum[row1-1][col2]+sum[row1-1][col1-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix = {
        {7, 7, 0},
        {-4, -7, 7},
        {-4, 0, -2},
        {-8, -5, 6}
                                  };
    NumMatrix nm(matrix);
    cout << nm.sumRegion(1, 0, 2, 2) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
