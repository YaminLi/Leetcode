//
//  main.cpp
//  47-permutation2
//
//  Created by Michael on 10/17/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        helper(res, tmp, used, nums);
        return res;
    }
    
    
private:
    void helper(vector<vector<int>>& res, vector<int>& tmp, vector<bool>& used, vector<int>& nums){
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return ;
        }
        for (int i=0; i<nums.size(); i++) {
            if(used[i]) continue;
            if (i>0 && !used[i-1] && nums[i] == nums[i-1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            used[i] = true;
            helper(res, tmp, used, nums);
            used[i] = false;
            tmp.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1, 2, 1};
    Solution st;
    vector<vector<int>> res = st.permuteUnique(a);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
