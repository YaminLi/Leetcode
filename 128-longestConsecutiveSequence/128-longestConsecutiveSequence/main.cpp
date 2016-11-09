//
//  main.cpp
//  128-longestConsecutiveSequence
//
//  Created by Michael on 11/9/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        map<int, int> mp;
        for (auto num:nums){
            mp[num] = 1;
        }
        int maxLen = 0;
        while (!mp.empty()){
            auto it = mp.begin();
            mp.erase(it->first);
            int len = 1;
            while ((it = mp.find(it->first+1)) != mp.end()){
                len++;
                mp.erase(it->first);
            }
            if (len > maxLen)
                maxLen = len;
        }
        return maxLen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> a = {100, 4, 200, 1, 3, 2};
    Solution st;
    cout << st.longestConsecutive(a) << endl;
    return 0;
}
