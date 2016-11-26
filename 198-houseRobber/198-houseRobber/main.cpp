//
//  main.cpp
//  198-houseRobber
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int rob(vector<int>& nums){
        int a=0;
        int b=0;
        for (int i=0; i<nums.size(); i++){
            if (i%2==0){
                a = max(nums[i]+a, b);
            }
            else {
                b = max(nums[i]+b, a);
            }
        }
        return max(a,b);
    }
    
    int rob1(vector<int>& nums){
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return helper(nums, 0);
    }
    
private:
    int helper(vector<int>& nums, int begin){
        if (begin >= nums.size()) return 0;
        if (begin == nums.size()-1) return nums[nums.size()-1];
        return max(nums[begin] + helper(nums, begin+2), nums[begin+1]+helper(nums, begin+3));
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
