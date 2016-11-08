//
//  main.cpp
//  14-longestCommonPrefix
//
//  Created by Michael on 10/5/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        if (strs.size() == 0) {
            return "";
        }
        else if(strs.size()==1)
            return strs[0];
        int len=0;
        for (len=0; len<strs[0].size(); ) {
            int i=1;
            while(i!=strs.size()-1) {
                if (len<strs[i].size() && strs[i][len] == strs[0][len]) {
                    i++;
                    continue;
                }
                else
                    break;
            }
            if (strs[i][len] == strs[0][len]) {
                len++;
            }
            else
                break;
        }
        return strs[0].substr(0, len);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> s={"aa", "ab"};
    Solution st;
    cout << st.longestCommonPrefix(s);
//    std::cout << "Hello, World!\n";
    return 0;
}
