//
//  main.cpp
//  224-basicCalculator
//
//  Created by Michael on 11/30/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution{
public:
    int calculate(string s){
        stack<int> nums, ops;
        int num=0;
        int res=0;
        int sign=1;
        for (int i=0; i<s.size(); i++){
            if (isdigit(s[i]))
                num = num*10+s[i]-'0';
            else{
                res += sign*num;
                num = 0;
                if (s[i] == '+') sign = 1;
                else if(s[i] == '-') sign = -1;
                else if (s[i] == '('){
                    nums.push(res);
                    ops.push(sign);
                    res = 0;
                    sign = 1;
                }
                else if (s[i] == ')' && ops.size()){
                    res = ops.top()*res+nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        res += sign*num;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.calculate("2+(3-6)") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
