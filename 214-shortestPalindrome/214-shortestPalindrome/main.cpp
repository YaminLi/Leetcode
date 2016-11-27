//
//  main.cpp
//  214-shortestPalindrome
//
//  Created by Michael on 11/26/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    string shortestPalindrome(string s){
        string t=s;
        reverse(t.begin(), t.end());
        int n=s.size(), i=0;
        for (i=n; i>=0; i--){
            if (s.substr(0, i) == t.substr(n-i)){
                break;
            }
        }
        return t.substr(0, n-i)+s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.shortestPalindrome("aacecaaa")<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
