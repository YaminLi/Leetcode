//
//  main.cpp
//  169-majorityElement
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums){
        if (nums.empty()) return 0;
        int majority, count=0;
        for (int i=0; i<nums.size(); i++){
            if (!count){
                majority = nums[i];
                count = 1;
            }
            else
                count += (nums[i] == majority)?1:-1;
        }
        return majority;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,3,1,3,1, 4};
    Solution st;
    cout << st.majorityElement(nums)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
