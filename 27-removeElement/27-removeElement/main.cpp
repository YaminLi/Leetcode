//
//  main.cpp
//  27-removeElement
//
//  Created by Michael on 10/7/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int j=0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == val) {
                continue;
            }
            else{
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
    
    int removeElement2(vector<int>& nums, int val){
        int n=nums.size();
        for (int i=0; i<n; ) {
            if (nums[i] == val) {
                swap(nums[i], nums[n-1]);
                n--;
            }
            else{
                i++;
            }
        }
        return n;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
