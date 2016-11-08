//
//  main.cpp
//  7-reverseInteger
//
//  Created by Michael on 10/4/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x){
        long res=0;
        while (x) {
            res = res*10 + x%10;
            x = x/10;
            if (res > INT_MAX || res<INT_MIN) {
                return 0;
            }
        }
        return (int)res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << -21%10 << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
