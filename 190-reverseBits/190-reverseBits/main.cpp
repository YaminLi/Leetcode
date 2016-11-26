//
//  main.cpp
//  190-reverseBits
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    uint32_t reverseBits(uint32_t n){
        int tb[16] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
        int cur = 0;
        uint32_t res = 0;
        uint32_t msk = 0xF;
        for (int i=0; i<8; i++){
            res <<= 4;
            cur = msk&n;
            res += tb[cur];
            n >>= 4;
        }
        return res;
    }
    
    uint32_t reverseBits1(uint32_t n){
        uint32_t res = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
           res = res*2;
           res += n%2;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    uint32_t n = 43261596;
    Solution st;
    cout << st.reverseBits(n) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
