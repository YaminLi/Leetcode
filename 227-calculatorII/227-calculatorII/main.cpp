//
//  main.cpp
//  227-calculatorII
//
//  Created by Michael on 12/1/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution{
public:
    int calculate(string s){
        stack<int> myStack;
        char sign = '+';
        int res = 0, tmp = 0;
        for (unsigned int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))
                tmp = 10*tmp + s[i]-'0';
            if ((!isdigit(s[i]) && !isspace(s[i])) || i == s.size()-1) {
                if (sign == '-')
                    myStack.push(-tmp);
                else if (sign == '+')
                    myStack.push(tmp);
                else {
                    int num;
                    if (sign == '*' )
                        num = myStack.top()*tmp;
                    else
                        num = myStack.top()/tmp;
                    myStack.pop();
                    myStack.push(num);
                }
                sign = s[i];
                tmp = 0;
            }
        }
        while (!myStack.empty()) {
            res += myStack.top();
            myStack.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.calculate("-1-5*3") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
