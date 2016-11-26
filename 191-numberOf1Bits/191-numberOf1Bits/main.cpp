//
//  main.cpp
//  191-numberOf1Bits
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int hammingWeight(uint32_t n){
        int res=0;
        for (int i=0; i<32; i++, n>>=1){
            res += n%2;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.hammingWeight(11)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
