//
//  main.cpp
//  136-singleNumber
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
        if (nums.empty()) return 0;
        int a = nums[0];
        for (int i=1; i<nums.size(); i++){
            a =  a^nums[i];
        }
        return a;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution st;
    vector<int> a = {1, 2, 3 ,1, 2};
    cout << st.singleNumber(a);
    return 0;
}
