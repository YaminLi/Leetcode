//
//  main.cpp
//  34-searchForARange
//
//  Created by Michael on 10/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> res;
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (nums[mid] == target) {
                left = right = mid;
                while (left>=0 && nums[left] == target) {
                    left--;
                }
                while (right<nums.size() && nums[right] == target) {
                    right++;
                }
                res.push_back(left+1);
                res.push_back(right-1);
                return res;
            }
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return *new vector<int> {-1, -1};
    }
    
    vector<int> searchRange2(vector<int>& nums, int target){
        vector<int> res;
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (nums[mid] >= target) {
                right = mid-1;
            }
            else
                left = mid+1;
        }
        int left1 = 0;
        int right1 = nums.size()-1;
        while (left1 <= right1) {
            int mid = left1+(right1-left1)/2;
            if (nums[mid] <= target) {
                left1 = mid+1;
            }
            else
                right1 = mid-1;
        }
        if (left <= right1) {
            res.push_back(left);
            res.push_back(right1);
            return res;
        }
        return *new vector<int> {-1,-1};
    }
    
//    vector<int> searchRange3(vector<int>& nums, int target){
//        vector<int> res(2, -1);
//        int left = 0;
//        int right = nums.size()-1;
//        while (left <= right) {
//            int mid = left+(right-left)/2;
//            if (nums[mid] == target) {
//                res[0] = helper(nums, left, mid, target);
//                res[1] = helper(nums, mid, right, target);
//                return res;
//            }
//            else if(nums[mid]>target)
//                right = mid-1;
//            else
//                left = mid+1;
//        }
//        return res;
//    }
    
//private:
//    int helper(vector<int>& nums, int left, int right, int target){
//        if (left == right) {
//            return left;
//        }
//        int mid = left+(right-left)/2;
//        if (nums[mid] == target) {
//            return helper(nums, left, mid, target);
//        }
//    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {0,0,0,1,2,3};
    Solution st;
    cout << st.searchRange2(a, 0)[0];
//    std::cout << "Hello, World!\n";
    return 0;
}
