//
//  main.cpp
//  93-restoreIPAddress
//
//  Created by Michael on 11/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> restoreIPAddress(string s){
        vector<string> res;
        string tmp;
        helper(res, tmp, s, 0, 0);
//        helper1(s, res, tmp, 0, 1);
        return res;
    }
    
private:
    bool isValid(string s){
        if (s.empty() || s.size() > 3) return false;
        if (s.size() > 1 && s[0]=='0') return false;
        int a = stoi(s);
        if (a >= 0 && a<=255)
            return true;
        return false;
    }
    
    void helper(vector<string>& res, string tmp, string s, int begin, int cnt){
        if (begin >= s.size()){
            return;
        }
        if (cnt == 3){
            string subs = s.substr(begin);
            if (isValid(subs)){
                res.push_back(tmp+"."+subs);
            }
            return;
        }
        for (int len=1; len<4; len++){
            if (begin+len < s.size()){
                string subs = s.substr(begin,len);
                if (isValid(subs)){
                    if (cnt == 0){
                        helper(res, subs, s, begin+len, cnt+1);
                    }
                    else{
                        helper(res, tmp+"."+subs, s, begin+len, cnt+1);
                    }
                }
            }
        }
    }
    
    void helper1(string s, vector<string>& res, string tmp, int begin, int count){
        if(begin >= s.size()) return;
        if(count == 4){
            string str = s.substr(begin);
            if(isValid(str)){
                res.push_back(tmp+"."+str);
            }
            return;
        }
        for(int i=1; i<4 && (begin+i) < s.size(); i++){
            string str = s.substr(begin, i);
            if(isValid(str)){
                if(count == 1)
                    helper1(s, res, str, begin+i, count+1);
                else
                    helper1(s, res, tmp+"."+str, begin+i, count+1);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<string> res = st.restoreIPAddress("0279245587303");
    for (auto s:res){
        cout << s << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
