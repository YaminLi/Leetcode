//
//  main.cpp
//  3-longestSubstring
//
//  Created by Michael on 9/22/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class Solution{
public:
    int longestSubstr(string s){
        if(s.length()<=1)  return s.length();
        int left=0;
        int right=0;
        int maxLen=0;
        map<char, int> myMap;
        while (right<s.length()) {
            if (myMap.find(s[right])==myMap.end()) {
                myMap[s[right]]=right;
                right++;
            }
            else{
                
                if (right-left>maxLen) {
                    maxLen = right-left;
                }
                while (s[left]!=s[right]) {
                    myMap.erase(s[left]);
                    left++;
                }
                left++;
                right++;
            }
        }
        maxLen = max(right-left, maxLen);
        return maxLen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    getline(cin, s);
    Solution sl;
    cout << sl.longestSubstr(s);
    std::cout << "Hello, World!\n";
    return 0;
}
