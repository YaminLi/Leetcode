//
//  main.cpp
//  167-twiSumII-InputArrayIsSorted
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        vector<int> res;
        int n=numbers.size();
        if (n<2) return res;
        int left = 0;
        int right = n-1;
        while (left < right){
            if (numbers[left]+numbers[right] == target){
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            else if (numbers[left]+numbers[right] < target)
                left++;
            else
                right--;
        }
        return res;
    }
    
    vector<int> twoSum2(vector<int>& numbers, int target){
        vector<int> res;
        int n=numbers.size();
        if (n<2) return res;
        for (int i=0; i<n; i++){
            int left = i+1;
            int right = n-1;
            int tmpTarget = target-numbers[i];
            while (left<=right){
                int mid = left+(right-left)/2;
                if (numbers[mid] == tmpTarget){
                    res.push_back(i+1);
                    res.push_back(mid+1);
                    break;
                }
                else if (numbers[mid] > tmpTarget)
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {2, 3, 4};
    Solution st;
    vector<int> res = st.twoSum(nums, 6);
    cout << res[0] << " " << res[1] << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
