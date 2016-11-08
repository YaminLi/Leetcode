//
//  main.cpp
//  18-4Sum
//
//  Created by Michael on 10/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-3; i++) {
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int target1 = target - nums[i];
            for (int j=i+1; j<nums.size()-2; j++) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int target2 = target1-nums[j];
                int left = j+1;
                int right = nums.size()-1;
                while (left<right) {
                    int sum = nums[left]+nums[right];
                    if (sum == target2) {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        res.push_back(tmp);
                        left++;
                        right--;
                        while (nums[left] == nums[left-1])
                            left++;
                        while (nums[right] == nums[right+1])
                            right--;
                    }
                    else if(sum > target2)
                        right--;
                    else
                        left++;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a={-1,0,-5,-2,-2,-4,0,1,-2};
    Solution st;
    cout << st.fourSum(a, -9).size() << endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
