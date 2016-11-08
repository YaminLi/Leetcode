//
//  main.cpp
//  33-searchInRotatedSortedArray
//
//  Created by Michael on 10/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > nums[left]){
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else if(nums[mid] < nums[right]){
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a={4, 5, 6, 7, 0, 1, 2};
    Solution st;
    cout << st.search(a, 6);
//    std::cout << "Hello, World!\n";
    return 0;
}
