//
//  main.cpp
//  172-fractionalTrailingZeroes
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int trailingZeroes(int n){
        return n==0?0:n/5+trailingZeroes(n/5);
    }
    
    int trailingZeroes1(int n) {
        int num = 0;
        for(long i=5; n/i>0; i *= 5){
            num += n/i;
        }
        return num;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.trailingZeroes(45)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
