//
//  main.cpp
//  282-expressionAddOperators
//
//  Created by Michael on 12/18/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> addOperators(string num, int target){
        vector<string> res;
        helper(num, target, res, "", 0, 0, 0);
        return res;
    }
    
    void helper(string num, int target, vector<string>& res, string tmp, int begin, long long tmpNum, long long last){
        if (begin == num.size() && tmpNum == target){
            res.push_back(tmp);
            return;
        }
        if (begin > num.size() || (begin == num.size() && tmpNum != target))
            return;
        for (int i=begin; i<num.size(); i++){
            if (i != begin && num[begin] == '0')
                break;
            long long curNum = stoll(num.substr(begin, i+1-begin));
            if (begin == 0){
                helper(num, target, res, to_string(curNum), i+1, curNum, curNum);
            }
            else{
                helper(num, target, res, tmp+"+"+to_string(curNum), i+1, tmpNum+curNum, curNum);
                helper(num, target, res, tmp+"-"+to_string(curNum), i+1, tmpNum-curNum, -curNum);
                helper(num, target, res, tmp+"*"+to_string(curNum), i+1, tmpNum-last+last*curNum, last*curNum);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<string> res = st.addOperators("3456237490", 9191);
    for (auto s:res)
        cout << s << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
