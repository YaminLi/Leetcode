//
//  main.cpp
//  239-slidingWindowMaximum
//
//  Created by Michael on 12/12/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        if (n==0) return *new vector<int>;
        deque<int> dq;
        vector<int> res;
        for (int i=0; i<n; i++){
            if (!dq.empty() && dq.front()==i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
    
    vector<int> maxSlidingWindow1(vector<int>& nums, int k){
        int n = nums.size();
        if (n==0) return *new vector<int>;
        vector<int> res(n-k+1);
        int left=0, right=k-1;
        while (right<n){
            res[left] = nums[left];
            for (int i=left+1; i<=right; i++)
                res[left] = max(res[left], nums[i]);
            left++;
            right++;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums= {1,3,-1,-3,5,3,6,7};
    Solution st;
    vector<int> res = st.maxSlidingWindow(nums, 3);
    for (auto num:res)
        cout << num << " ";
    cout << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
