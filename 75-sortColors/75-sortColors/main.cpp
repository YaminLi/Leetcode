//
//  main.cpp
//  75-sortColors
//
//  Created by Michael on 10/23/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void sortColors(vector<int>& nums){
        int cnt1 = 0;
        int cnt2 = nums.size()-1;
        int i=0;
        while (i <= cnt2) {
            if (nums[i]==0) {
                swap(nums[i++], nums[cnt1++]);
            }
            else if (nums[i] == 1)
                i++;
            else
                // cnt2的值未知，i不增，继续判断
                swap(nums[i], nums[cnt2--]);
        }
        return;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1, 0, 0, 1, 0, 2, 0, 1, 2, 2, 1, 2};
    Solution st;
    st.sortColors(a);
    for ( int i=0; i<a.size(); i++) {
        cout << a[i] << " " ;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
