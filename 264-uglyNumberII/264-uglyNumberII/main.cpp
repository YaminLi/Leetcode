//
//  main.cpp
//  264-uglyNumberII
//
//  Created by Michael on 12/13/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int nthUglyNumber(int n) {
        if (n<=0) return 0;
        vector<int> res(n);
        res[0] = 1;
        int l1=0, l2=0, l3=0;
        for (int i=1; i<n; i++){
            res[i]=min(res[l1]*2, min(res[l2]*3, res[l3]*5));
            if (res[i] == res[l1]*2) l1++;
            if (res[i] == res[l2]*3) l2++;
            if (res[i] == res[l3]*5) l3++;
        }
        return res[n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
