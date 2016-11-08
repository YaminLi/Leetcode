//
//  main.cpp
//  70-climbingStairs
//
//  Created by Michael on 10/21/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int climbStairs(int n){
        if (n == 1) {
            return 1;
        }
        int a=1;
        int b=2;
        for (int i=2; i<n; i++) {
            int tmp = a+b;
            a = b;
            b = tmp;
        }
        return b;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
