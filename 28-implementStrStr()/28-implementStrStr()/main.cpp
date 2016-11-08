//
//  main.cpp
//  28-implementStrStr()
//
//  Created by Michael on 10/7/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle){
        int n = needle.size();
        int m=haystack.size();
        if (!n) {
            return -1;
        }
        for (int i=0; i<(m-n+1); i++) {
            if (haystack[i] == needle[0]) {
                if (haystack.substr(i, n)==needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string a="ab";
    string b="abaaa";
    Solution st;
    cout << st.strStr(a, b);
//    std::cout << "Hello, World!\n";
    return 0;
}
