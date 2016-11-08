//
//  main.cpp
//  31-nextPermutation
//
//  Created by Michael on 10/7/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int pos = -1;
        for (int i=nums.size()-1; i>0; i--) {
            if (nums[i]>nums[i-1]) {
                pos = i-1;
                break;
            }
        }
        if (pos == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i=nums.size()-1; i>pos; i--) {
            if (nums[i]>nums[pos]) {
                swap(nums[i], nums[pos]);
                break;
            }
        }
        reverse(nums.begin()+pos+1, nums.end());
        return;

    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1, 3, 2};
    Solution st;
    st.nextPermutation(a);
    for (int i=0; i<a.size(); i++) {
        cout << a[i];
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
