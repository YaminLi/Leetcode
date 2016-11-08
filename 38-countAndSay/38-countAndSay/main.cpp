//
//  main.cpp
//  38-countAndSay
//
//  Created by Michael on 10/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string countAndSay(int n){
        string res="1";
        for (int i=1; i<n; i++) {
            res = helper(res);
        }
        return res;
    }
private:
    string helper(string s){
        string res;
        int cnt=1;
        int n = s.size();
        for (int i=1; i<n; i++) {
            if (s[i] == s[i-1]) {
                cnt++;
            }
            else{
                res.push_back(cnt+'0');
                res.push_back(s[i-1]);
                cnt = 1;
            }
        }
        res.push_back(cnt+'0');
        res.push_back(s[n-1]);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.countAndSay(5);
//    std::cout << "Hello, World!\n";
    return 0;
}
