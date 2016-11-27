//
//  main.cpp
//  215-kthLargestElementInAnArray
//
//  Created by Michael on 11/26/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findKthLargest(vector<int>& nums, int k){
        int left=0;
        int right = nums.size()-1;
        while (true){
            int pos = partition(nums, left, right);
            if (pos == k-1) return nums[pos];
            else if (pos < k-1) left = pos+1;
            else right = pos-1;
        }
        return left;
    }
    
private:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int i=left+1;
        int j=right;
        while (i<=j){
            if (nums[i]<pivot && nums[j]>pivot){
                swap(nums[i], nums[j]);
            }
            if (nums[i] >= pivot) i++;
            if (nums[j] <= pivot) j--;
        }
        swap(nums[j], nums[left]);
        return j;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums={1, 9, 2, 3, 1, 6};
    Solution st;
    cout << st.findKthLargest(nums,2) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
