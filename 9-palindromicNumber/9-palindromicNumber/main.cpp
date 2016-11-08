//
//  main.cpp
//  9-palindromicNumber
//
//  Created by Michael on 10/4/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        if (x<0) {
            return false;
        }
        int p = x;
        int q = 0;
        while (x/10) {
            q = q*10+x%10;
            x = x/10;
        }
        return q==p/10 && x==p%10;
    }
    
    bool isPalindrome2(int x){
        if (x<0 || (x!=0 && x%10==0)) {
            return false;
        }
        int p=0;
        while (x>p) {
            p = p*10+x%10;
            x=x/10;
        }
        return x==p || x==p/10;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    if(s.isPalindrome2(101))
        std::cout << "Hello, World!\n";
    return 0;
}
