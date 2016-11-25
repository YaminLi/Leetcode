//
//  main.cpp
//  179-largestNumber
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//struct cmp{
//    bool operator() (int a, int b){
//        return to_string(a)+to_string(b) > to_string(b)+to_string(a);
//    }
//};

class Solution{
public:
    string largestNumber(vector<int>& nums){
        sort(nums.begin(), nums.end(), [](int a, int b){return to_string(a)+to_string(b) > to_string(b)+to_string(a);});
        string res;
        for (auto num:nums){
            res+= to_string(num);
        }
        return res[0]=='0'? "0": res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {3, 30, 34, 5, 9};
    Solution st;
    cout << st.largestNumber(nums) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
