//
//  main.cpp
//  152-maximumProductSubarray
//
//  Created by Michael on 11/21/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProduct(vector<int>& nums){
        if (nums.empty()) return 0;
        int res = nums[0];
        int maxProduct = nums[0];
        int minProduct = nums[0];
        for (int i=1; i<nums.size(); i++){
            int tmp = maxProduct;
            maxProduct = max(max(maxProduct*nums[i], minProduct*nums[i]), nums[i]);
            minProduct = min(min(tmp*nums[i], minProduct*nums[i]), nums[i]);
            res = max(res, maxProduct);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {-1, 2, -3, 3};
    Solution st;
    cout << st.maxProduct(nums)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
