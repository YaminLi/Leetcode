//
//  main.cpp
//  60-permutationSequence
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    string getPermutation(int n, int k){
        vector<int> nums(n);
        string res;
        int fact_i = 1;
        for (int i=0; i<n; i++) {
            nums[i] = i+1;
            fact_i *= (i+1);
        }
        for (int i=0; i<n; i++) {
            fact_i = fact_i/(n-i);
            int idx = k/fact_i;
            res.push_back(nums[idx] + '0');
            for (int j=idx; j<n-i-1; j++) {
                nums[j] = nums[j+1];
            }
            k = k%fact_i;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.getPermutation(4, 2);
//    std::cout << "Hello, World!\n";
    return 0;
}
