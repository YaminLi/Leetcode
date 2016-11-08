//
//  main.cpp
//  96-uniqueBinarySearchTrees
//
//  Created by Michael on 11/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int numTrees(int n){
        if (n==0) return 1;
        if (n==1) return 1;
        int res=0;
        for (int i=1; i<=n; i++){
            int l = numTrees(i-1);
            int r = numTrees(n-i);
            res = res+l*r;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.numTrees(19) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
