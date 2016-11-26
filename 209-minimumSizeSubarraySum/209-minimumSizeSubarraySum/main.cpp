//
//  main.cpp
//  209-minimumSizeSubarraySum
//
//  Created by Michael on 11/26/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minSubArrayLen(int s, vector<int>& nums){
        int left=0, right=0;
        int minLen = INT_MAX;
        int sum = 0;
        while (right<nums.size()){
            while (right<nums.size() && sum<s){                                sum += nums[right];
                right++;
            }
            while (left<nums.size() && sum>=s){
                if (sum >= s){
                    minLen = min(minLen, right-left);
                }
                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0:minLen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3,4,5};
    Solution st;
    cout << st.minSubArrayLen(11, nums) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
