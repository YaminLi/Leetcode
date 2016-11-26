//
//  main.cpp
//  201-bitwiseAndOfNumbersRange
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int rangeBitwiseAnd(int m, int n){
//        if (m>n) return 0;
//        int res = m;
//        while (n>m){
//            res = res&n;
//            n--;
//        }
//        return res;
        int i=0;
        while (m != n){
            m >>= 1;
            n >>= 1;
            i++;
        }
        return m<<i;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.rangeBitwiseAnd(1, 7) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
