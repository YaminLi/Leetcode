//
//  main.cpp
//  154-findMinimumInRotatedSortedArrayII
//
//  Created by Michael on 11/21/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findMin(vector<int>& nums){
        if (nums.empty()) return 0;
        int left = 0;
        int right = nums.size()-1;
        while (left < right){
            if (nums[left] < nums[right]) return nums[left];
            int mid = left+(right-left)/2;
            if (nums[left] == nums[right]) left++;
            else if (nums[mid] >= nums[left]) left = mid+1;
            else if (nums[mid] <= nums[right]) right = mid;
        }
        return nums[left];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {3, 1, 1};
    Solution st;
    cout << st.findMin(nums) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
