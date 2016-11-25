//
//  main.cpp
//  162-findPeakElement
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findPeakElement(vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            if (left == right) return left;
            int mid = left+(right-left)/2;
            if (nums[mid]>nums[mid+1])
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3,4,2,1};
    Solution st;
    cout << st.findPeakElement(nums);
    std::cout << "Hello, World!\n";
    return 0;
}
