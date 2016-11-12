//
//  main.cpp
//  137-singleNumberII
//
//  Created by Michael on 11/12/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int singleNumber(vector<int>& nums){
        int count[32] = {0};
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<32; j++){
                if(nums[i] & (1 << j))
                    count[j]++;
            }
        }
        for(int j=0; j<32; j++){
            if(count[j] % 3){
                res += (1<<j);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<int> nums = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
    cout << st.singleNumber(nums);
//    std::cout << "Hello, World!\n";
    return 0;
}
