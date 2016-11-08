//
//  main.cpp
//  35-searchInsertPosition
//
//  Created by Michael on 10/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int searchInsert(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1, 3, 5, 6};
    Solution st;
    cout << st.searchInsert(a, 0);
//    std::cout << "Hello, World!\n";
    return 0;
}
