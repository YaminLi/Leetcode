//
//  main.cpp
//  119-Pascal'sTriangleII
//
//  Created by Michael on 11/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int>  getRow(int rowIndex){
        if (rowIndex < 0) return *new vector<int>;
        if (rowIndex == 0) return *new vector<int>{1};
        if (rowIndex == 1) return *new vector<int>{1,1};
        vector<int> res(rowIndex+1);
        vector<int> tmp = getRow(rowIndex-1);
        res[0] = 1;
        for (int i=1; i<rowIndex; i++){
            res[i] = tmp[i-1]+tmp[i];
        }
        res[rowIndex] =1;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<int> res = st.getRow(3);
    for (int i=0; i<res.size(); i++){
        cout << res[i];
    }
    std::cout << "Hello, World!\n";
    return 0;
}
