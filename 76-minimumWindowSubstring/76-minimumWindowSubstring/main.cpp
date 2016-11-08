//
//  main.cpp
//  76-minimumWindowSubstring
//
//  Created by Michael on 10/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    string minWindow(string s, string t){
        string res;
        if (s.empty() || t.empty()) {
            return res;
        }
        vector<int> m(128, 0);
        int left = 0;
        int right = 0;
        int minStart = 0;
        int minLen = s.size()+1;
        int count = 0;
        for (int i=0; i<t.size(); i++) {
            m[t[i]]++;
        }
        while (right < s.size()) {
            if (m[s[right]] > 0) {
                count++;
            }
            m[s[right]]--;
            while (count == t.size()) {
                if (right-left+1 < minLen ) {
                    minLen = right-left+1;
                    minStart = left;
                }
                if (m[s[left]] == 0) {
                    count--;
                }
                m[s[left]]++;
                left++;
            }
            right++;
        }
        return minLen > s.size() ? "" :s.substr(minStart, minLen);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.minWindow("ADOBECODEBANC", "ABC") << endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
