//
//  main.cpp
//  205-isomorphicStrings
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool isIsomorphic(string s, string t){
        if (s.size() != t.size()) return false;
        unordered_map<char, int> sMp;
        unordered_map<char, int> tMp;
        for (int i=0; i<s.size(); i++){
            if (sMp[s[i]] != tMp[t[i]]) return false;
            sMp[s[i]] = i+1;
            tMp[t[i]] = i+1;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    if (st.isIsomorphic("paper", "title"))
        std::cout << "Hello, World!\n";
    return 0;
}
