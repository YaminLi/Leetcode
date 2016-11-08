//
//  main.cpp
//  32-longestValidParentheses
//
//  Created by Michael on 10/7/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution{
public:
    int longestValidParentheses(string s){
        stack<int> sk;
        int maxLen = 0;
        sk.push(-1);
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                sk.push(i);
            }
            else{
                if (sk.top()!=-1 && s[sk.top()] == '(') {
                    sk.pop();
                    maxLen = max(maxLen, i-sk.top());
                }
                else{
                    sk.push(i);
                }
            }
        }
        return maxLen;
    }
    
    int longestValidParentheses2(string s){
        int maxLen = 0;
        int n = s.size();
//       以s_(i-1)结尾的最长有效子串长度
        vector<int> dp(n+1, 0);
        for (int i=1; i<n; i++) {
            int j = i-2-dp[i-1];
            if (s[i-1]=='(' || j<0 || s[j] == ')') {
                dp[i] = 0;
            }
            else{
                dp[i] = dp[i-1]+2+dp[j];
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = ")()())()()(";
    Solution st;
    cout << st.longestValidParentheses2(s);
//    std::cout << "Hello, World!\n";
    return 0;
}
