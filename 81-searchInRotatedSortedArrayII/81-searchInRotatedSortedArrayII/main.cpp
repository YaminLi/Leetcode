//
//  main.cpp
//  81-searchInRotatedSortedArrayII
//
//  Created by Michael on 11/5/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool search(vector<int>& nums, int target){
        int left=0, right=nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[mid] > nums[left]){
                if (nums[mid] > target && target >= nums[left]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else if (nums[mid] < nums[left]){
                if (nums[mid] < target && target <= nums[right]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            else
                left++;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<int> a={3,1,1};
    if (st.search(a, 3)){
        std::cout << "Hello, World!\n";
    }
    return 0;
}
