//
//  main.cpp
//  20-validParentheses
//
//  Created by Michael on 10/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
public:
    bool isValid(string s){
        stack<char> st;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
                st.push(s[i]);
            }
            else{
                switch (s[i]) {
                    case ')':
                        if (st.empty() || st.top()!='(') {
                            return false;
                        }
                        else
                            st.pop();
                        break;
                    case ']':
                        if (st.empty() || st.top()!='[') {
                            return false;
                        }
                        else
                            st.pop();
                        break;
                    case '}':
                        if (st.empty() || st.top()!='{') {
                            return false;
                        }
                        else
                            st.pop();
                        break;
                    default:
                        break;
                }
            }
        }
        return st.empty();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
