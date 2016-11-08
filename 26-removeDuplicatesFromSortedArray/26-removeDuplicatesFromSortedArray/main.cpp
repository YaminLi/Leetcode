//
//  main.cpp
//  26-removeDuplicatesFromSortedArray
//
//  Created by Michael on 10/7/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int len=nums.size();
        if (len <= 1) {
            return len;
        }
        int j=1;
        for (int i=1; i<len; i++) {
            if (nums[i] == nums[i-1])
                continue;
            else{
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a={1, 1, 2};
    Solution st;
    cout << st.removeDuplicates(a) << endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
