//
//  main.cpp
//  22-generateParentheses
//
//  Created by Michael on 10/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> res;
        helper(res, "", 0, 0, n);
        return res;
    }
    
private:
    void helper(vector<string>& res, string s, int left, int right, int n){
        if (left<n) {
            helper(res, s+"(", left+1, right, n);
        }
        if (right < left && right<n) {
            helper(res, s+")", left, right+1, n);
        }
        if (right == n && left == right) {
            res.push_back(s);
            cout << s << endl;
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution st;
    vector<string> r = st.generateParenthesis(3);
    cout << r.size()<< endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
