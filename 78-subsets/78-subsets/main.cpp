//
//  main.cpp
//  78-subsets
//
//  Created by Michael on 10/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i=0; i <= nums.size(); i++) {
            helper(res, tmp, nums, 0, i);
        }
        return res;
    }
    
private:
    void helper(vector<vector<int>>& res, vector<int>& tmp, vector<int> nums, int begin, int len){
        if (len == 0) {
            res.push_back(tmp);
            return ;
        }
        for (int i=begin; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
            helper(res, tmp, nums, i+1, len-1);
            tmp.pop_back();
        }
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums={1, 2, 3};
    Solution st;
    vector<vector<int>> a = st.subsets(nums);
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
