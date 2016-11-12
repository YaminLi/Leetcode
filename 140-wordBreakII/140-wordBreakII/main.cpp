//
//  main.cpp
//  140-wordBreakII
//
//  Created by Michael on 11/12/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordList){
        vector<string> res;
        string tmp;
        helper(res, tmp, s, wordList, 0);
        return res;
    }
    
private:
    void helper(vector<string>& res, string tmp, string s, unordered_set<string>& wordList, int begin){
        if (begin == s.size()){
            res.push_back(tmp);
            return;
        }
        for (int i=begin; i<s.size(); i++){
            string subs = s.substr(begin, i-begin+1);
            if (wordList.find(subs)!= wordList.end()){
                if (begin==0) helper(res, subs, s, wordList, i+1);
                else helper(res, tmp+" "+subs, s, wordList, i+1);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    unordered_set<string> wordList = {"cat", "cats", "and", "sand", "dog"};
    Solution st;
    vector<string> res = st.wordBreak("catsanddog", wordList);
    cout << res.size() << endl;
    for (int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
