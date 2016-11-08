//
//  main.cpp
//  15-3Sum
//
//  Created by Michael on 10/5/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Soluction{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; i++) {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int target = 0-nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while (left<right) {
                if (nums[left]+nums[right]<target) {
                    left++;
                }
                else if(nums[left]+nums[right]>target){
                    right--;
                }
                else{
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);
                    while (left<right && nums[left] == tmp[1])
                        left++;
                    while (left<right && nums[right] == tmp[2]) {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {0,0,0,0};
    Soluction st;
    cout << st.threeSum(nums).size() << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
