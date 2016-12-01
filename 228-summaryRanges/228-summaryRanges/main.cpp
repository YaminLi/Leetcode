//
//  main.cpp
//  228-summaryRanges
//
//  Created by Michael on 11/30/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> summaryRanges(vector<int>& nums){
        vector<string> res;
        if (nums.empty()) return res;
        int begin=0, end=0;
        int n=nums.size();
        for (int i=0; i<n; i++){
            begin = nums[i];
            while (i<n-1 && nums[i+1]==nums[i]+1)
                i++;
            end = nums[i];
            if (end==begin){
                res.push_back(to_string(begin));
            }
            else{
                res.push_back(to_string(begin)+"->"+to_string(end));
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    Solution st;
    vector<string> res = st.summaryRanges(nums);
    for (auto s:res)
        cout << s << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
