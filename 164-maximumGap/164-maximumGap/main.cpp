//
//  main.cpp
//  164-maximumGap
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maximumGap1(vector<int>& nums){
        int n=nums.size();
        if (n<2) return 0;
        int maxNum = nums[0];
        int minNum = nums[0];
        for (auto num:nums){
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
        }
        int len = (maxNum-minNum)/n+1;
        vector<vector<int> > buckets((maxNum-minNum)/len+1);
        for (auto num:nums){
            int i = (num-minNum)/len;
            if (buckets[i].empty()){
                buckets[i].reserve(2);
                buckets[i].push_back(num);
                buckets[i].push_back(num);
            }
            else {
                if (num<buckets[i][0]) buckets[i][0] = num;
                if (num>buckets[i][1]) buckets[i][1] = num;
            }
        }
        
        int gap = 0;
        int prev = 0;
        for (int i=1; i<buckets.size(); i++){
            if (buckets[i].empty()) continue;
            gap = max(gap, buckets[i][0]-buckets[prev][1]);
            prev = i;
        }
        return gap;
    }
    
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        //遍历一遍，找出最大最小值
        int maxNum = num[0];
        int minNum = num[0];
        for (int i : num) {
            maxNum=max(maxNum,i);
            minNum=min(minNum,i);
        }
        // 每个桶的长度len,向上取整所以加+
        int len = (maxNum - minNum) / num.size() + 1;
        
        //桶的个数:(maxNum - minNum) / len + 1,每个桶里面存储属于该桶的最大值和最小值即可，注意这里的最大最小值是局部的
        vector<vector<int>> buckets((maxNum - minNum) / len + 1);
        for (int x : num) {
            int i = (x - minNum) / len;
            if (buckets[i].empty()) {
                buckets[i].reserve(2);
                buckets[i].push_back(x);
                buckets[i].push_back(x);
            } else {
                if (x < buckets[i][0]) buckets[i][0] = x;
                if (x > buckets[i][1]) buckets[i][1] = x;
            }
        }
        //gap的计算，For each non-empty buckets p, find the next non-empty buckets q, return min（ q.min - p.max ）
        int gap = 0;
        int prev = 0;
        for (int i = 1; i < buckets.size(); i++) {
            if (buckets[i].empty()) continue;
            gap = max(gap, buckets[i][0] - buckets[prev][1]);
            prev = i;
        }
        return gap;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1, 5, 4, 2, 9, 2};
    Solution st;
    cout << st.maximumGap1(nums)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
