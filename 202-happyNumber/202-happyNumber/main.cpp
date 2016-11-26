//
//  main.cpp
//  202-happyNumber
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool isHappy(int n){
        unordered_map<int, int> mp;
        while (n != 1){
            if (mp.find(n) != mp.end()) return false;
            mp[n] = 1;
            int tmp = 0;
            while (n){
                tmp += pow((n%10), 2);
                n /= 10;
            }
            n = tmp;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    if (st.isHappy(2))
        std::cout << "Hello, World!\n";
    return 0;
}
