//
//  main.cpp
//  279-perfectSquares
//
//  Created by Michael on 12/18/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n){
        if (n <= 0) return 0;
        vector<int> res(n+1, INT_MAX);
        res[0] = 0;
        for (int i=1; i<=n; i++){
            for (int j=1; j*j <= i; j++){
                res[i] = min(res[i], res[i-j*j]+1);
            }
        }
        return res[n];
    }
    
    int numSquares1(int n) {
        vector<int> nums;
        for (int i=1; i*i <= n; i++){
            nums.push_back(i*i);
        }
        
        int res=INT_MAX;
        helper(nums, n, 0, 0, 0, res);
        return res;
    }
    
    void helper(vector<int>& nums, int n, int tmp, int cnt, int begin, int& res){
        if (tmp == n){
            res = min(res, cnt);
            return;
        }
        if (tmp > n)    return;
        for (int i=begin; i<nums.size(); i++){
            if (tmp+nums[i] <= n){
                helper(nums, n, tmp+nums[i], cnt+1, i, res);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.numSquares(196) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
