//
//  main.cpp
//  17-letterCombinationsOfaPhoneNumber
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
    vector<string> letterCombinations(string digits){
        vector<string> res;
        if (digits.size()==0) return res;
        string c[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.size()==1) {
            for (int i=0; i<c[digits[0]-'0'].size(); i++) {
                string s;
                s.push_back(c[digits[0]-'0'][i]);
                res.push_back(s);
            }
            return res;
        }
        int len = digits.size();
        vector<string> tmp=letterCombinations(digits.substr(0, len-1));
//        cout << digits[len-1]-'0' << endl;
        for(int i=0; i<tmp.size(); i++){
            for (int j=0;j<c[digits[len-1]-'0'].size(); j++) {
                string s = tmp[i];
                s.push_back(c[digits[len-1]-'0'][j]);
                res.push_back(s);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "23";
    Solution st;
    cout << st.letterCombinations(s).size() << endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
