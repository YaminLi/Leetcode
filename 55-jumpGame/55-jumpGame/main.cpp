//
//  main.cpp
//  55-jumpGame
//
//  Created by Michael on 10/17/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool canJump(vector<int>& nums){
        int end = 0;
        int i = 0;
        for (; i<nums.size() && i<=end; i++) {
            end = max(i+nums[i], end);
        }
        return i==nums.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
