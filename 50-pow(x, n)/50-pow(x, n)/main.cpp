//
//  main.cpp
//  50-pow(x, n)
//
//  Created by Michael on 10/17/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

class Solution{
public:
    double myPow(double x, int n){
        if(n==0) return 1;
        if(n<0){
            n=-n;
            x = 1/x;
        }
        return (n%2 == 0)? myPow(x*x, n/2): x*myPow(x*x, n/2);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
