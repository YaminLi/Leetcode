//
//  main.cpp
//  80-removeDuplicates
//
//  Created by Michael on 10/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int twice = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i==0 || (i > 0 && nums[i]==nums[i-1] && twice < 2)) {
                twice++;
                nums[cnt] = nums[i];
                cnt++;
            }
            else if(i > 0 && nums[i]==nums[i-1] && twice >= 2){
                continue;
            }
            else{
                twice = 1;
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1, 1,1, 2, 2, 3};
    Solution st;
    cout << st.removeDuplicates(a)<< endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
