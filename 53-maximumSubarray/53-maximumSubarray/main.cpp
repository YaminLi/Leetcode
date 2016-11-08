//
//  main.cpp
//  53-maximumSubarray
//
//  Created by Michael on 10/18/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxSubArray2(vector<int>& nums){
        //1. 状态dp[i]：以A[i]为最后一个数的所有max subarray的和。
        //2. 通项公式：dp[i] = dp[i-1]<=0 ? dp[i] : dp[i-1]+A[i]
        //3. 由于dp[i]仅取决于dp[i-1]，所以可以仅用一个变量来保存前一个状态，而节省内存。
        if (nums.empty())
            return 0;
        int maxSum = nums[0];
        int dp = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (dp <= 0) {
                dp = nums[i];
            }
            else{
                dp = dp + nums[i];
            }
            maxSum = max(maxSum, dp);
        }
        return maxSum;
    }
    
    int maxSubArray(vector<int>& nums){
        //假设数组A[left, right]存在最大值区间[i, j](i>=left & j<=right)，以mid = (left + right)/2 分界，无非以下三种情况：
        //subarray A[i,..j] is
        //(1) Entirely in A[low,mid-1]
        //(2) Entirely in A[mid+1,high]
        //(3) Across mid
        //对于(1) and (2)，直接递归求解即可，对于(3)，则需要以min为中心，向左及向右扫描求最大值，意味着在A[left, Mid]区间中找出A[i..mid], 而在A[mid+1, right]中找出A[mid+1..j]，两者加和即为(3)的解
        int left = 0;
        int right = nums.size()-1;
        return helper(nums, left, right);
    }
    
private:
    int helper(vector<int>& nums, int left, int right){
        if (left > right) {
            return INT_MIN;
        }
        int mid = left+(right-left)/2;
        int lmax = helper(nums, left, mid-1);
        int rmax = helper(nums, mid+1, right);
        int sum1 =0, lmmax = 0;
        for(int i=mid-1; i>=left; i--) {
            sum1 += nums[i];
            if (sum1 > lmmax) {
                lmmax = sum1;
            }
        }
        int sum2 = 0, mrmax = 0;
        for (int j=mid+1; j<=right; j++) {
            sum2 += nums[j];
            if (sum2 > mrmax) {
                mrmax = sum2;
            }
            
        }
    
        return max(lmmax+mrmax+nums[mid], max(lmax, rmax));
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a= {-2,1,-3,4,-1,2,1,-5,4};
    Solution st;
    cout << st.maxSubArray(a)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
