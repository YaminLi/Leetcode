//
//  main.cpp
//  4-longestPalindromicSubstring
//
//  Created by Michael on 10/3/16.
//  Copyright © 2016 Michael. All rights reserved.
//

// https://segmentfault.com/a/1190000003914228

#include <iostream>

using namespace std;

class Solution{
public:
    string brute_force(string s){
        string res;
        int maxLen=0;
        for(int len = 1; len<=s.length(); len++){
            for(int i=0; i+len<=s.length(); i++){
                string subs = s.substr(i, len);
                if (isPalindromic(subs) && len>maxLen) {
                    maxLen = len;
                    res = subs;
                }
            }
        }
        return res;
    }
    
    string longestPalindrome(string s){
        string res;
        int maxLen = 0;
        for(int i=0; i<s.size(); i++){
            for (int len=1; i-len>=0 && i+len-1<s.size(); len++) {
                string subs = s.substr(i-len, 2*len);
                if(isPalindromic(subs) && 2*len>maxLen){
                    maxLen = 2*len;
                    res = subs;
                }
            }
            for (int len=0; i-len>=0 && i+len<s.size(); len++) {
                string subs = s.substr(i-len, 2*len+1);
                if (isPalindromic(subs) && (2*len+1)>maxLen) {
                    maxLen = 2*len+1;
                    res = subs;
                }
            }
        }
        return res;
    }
    
    string longestPalindrome2(string s){
        int n=s.length();
        bool isPalindrome[1000][1000]={false};
        int start=0;
        int maxLen = 1;
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j<n; j++) {
                if (s[i]==s[j] && (i+1>j-1 || isPalindrome[i+1][j-1])) {
                    isPalindrome[i][j] = true;
                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
    
private:
    bool isPalindromic(string s){
        if (s.length() <= 1) {
            return true;
        }
        else{
            int i=0;
            int j=s.length()-1;
            while (j >= i ) {
                if (s[i] != s[j]) {
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    getline(cin, s);
    Solution st;
    //    if(st.isPalindromic(s))
    std::cout << st.longestPalindrome2(s)<< endl;
    return 0;
}
