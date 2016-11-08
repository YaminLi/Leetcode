//
//  main.cpp
//  15-3SumCloest
//
//  Created by Michael on 10/5/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumCloest(vector<int>& nums, int target){
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        for (int i=0; i<nums.size()-1; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int left=i+1;
            int right = nums.size()-1;
            while (left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                if (sum == target) {
                    return target;
                }
                else if(abs(target - sum) < abs(target-res)) res = sum;
                if (sum < target) {
                    left++;
                }
                else if(sum > target){
                    right--;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {-1, 2, 1, 4};
    Solution st;
    cout << st.threeSumCloest(a, 1);
    //    std::cout << "Hello, World!\n";
    return 0;
}
