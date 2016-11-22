//
//  main.cpp
//  151-ReverseWordsInAString
//
//  Created by Michael on 11/21/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    void reverseWords(string &s){
        string res;
        int j=s.size();
        for (int i=s.size()-1; i>=0; i--){
            if (s[i] == ' '){
                j=i;
            }
            else if (i==0 || s[i-1] == ' '){
                if (!res.empty()) res.append(" ");
                res.append(s.substr(i, j-i));
            }
        }
        s = res;
        return;
    }
    
    void reverseWords1(string &s){
        if (s.empty()) return;
        for (auto it = s.begin(); it != s.end();){
            while (it != s.end() && *it == ' '){
                it++;
            }
            if (it == s.end()) break;
            auto wordStart = it;
            while (it != s.end() && *it != ' ')
                it++;
            auto wordEnd = it;
            reverse(wordStart, wordEnd);
        }
        reverse(s.begin(), s.end());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    string s = "the sky is blue";
    st.reverseWords(s);
    cout << s << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
