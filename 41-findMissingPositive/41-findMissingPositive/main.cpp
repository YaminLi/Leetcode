//
//  main.cpp
//  41-findMissingPositive
//
//  Created by Michael on 10/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int firstMissingPosition(vector<int>& nums){
        int n=nums.size();
        for (int i=0; i<n; i++) {
            while (nums[i]>0 && nums[i] <= n && nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i=0; i<n; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a={3, 4, -1, 1};
    Solution st;
    cout << st.firstMissingPosition(a);
//    std::cout << "Hello, World!\n";
    return 0;
}
