//
//  main.cpp
//  139-wordBreak
//
//  Created by Michael on 11/12/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool wordBreak(string s, unordered_set<string>& wordList){
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i=0; i<n; i++)
            for (int j=i; j>=0; j--){
                string subs = s.substr(j, i-j+1);
                if (dp[j] && wordList.find(subs)!=wordList.end()){
                    dp[i+1] = true;
                    break;
                }
            }
        return dp[n];
    }
    
    bool wordBreak1(string s, unordered_set<string>& wordList){
        return helper(s, wordList);
    }
    
private:
    bool helper(string s, unordered_set<string>& wordList){
        if (wordList.find(s) != wordList.end())
            return true;
        for (int len = 1; len<=s.size(); len++){
            string subs = s.substr(0, len);
            if (wordList.find(subs) != wordList.end()){
                if (helper(s.substr(len), wordList))
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    unordered_set<string> wordList;
    wordList.insert("leet");
    wordList.insert("code");
//    wordList.insert("bbbb");
    if (st.wordBreak("leetcode", wordList))
        std::cout << "Hello, World!\n";
    return 0;
}
