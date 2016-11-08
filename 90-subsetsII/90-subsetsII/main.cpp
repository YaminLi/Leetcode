//
//  main.cpp
//  90-subsetsII
//
//  Created by Michael on 11/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(const int a, const int b){
        return a < b;
    }
};

class Solution{
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums){
        cmp myCmp;
        sort(nums.begin(), nums.end(), myCmp);
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, nums, 0);
        return res;
    }
    
private:
    void helper(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int begin){
        res.push_back(tmp);
        for (int i=begin; i<nums.size(); i++){
            if (i>begin && nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            helper(res, tmp, nums, i+1);
            tmp.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1, 2, 2};
    Solution st;
    vector<vector<int>> res = st.subsetsWithDup(a);
    for (auto v: res){
        for (auto num: v)
            cout << num << " ";
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
