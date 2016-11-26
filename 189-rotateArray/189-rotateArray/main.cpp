//
//  main.cpp
//  189-rotateArray
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void rotate(vector<int>& nums, int k){
        if (k<=0) return;
        int n=nums.size();
        k = k%n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3,4,5,6,7};
    Solution st;
    st.rotate(nums, 3);
    for (auto num:nums)
        cout << num << " ";
    cout << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
