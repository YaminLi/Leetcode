//
//  main.cpp
//  150-evaluateReversePolishNotation
//
//  Created by Michael on 11/13/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class RPN{
public:
    int evalRPN(vector<string>& tokens){
        stack<int> stk;
        int res = 0;
        for (int i=0; i<tokens.size(); i++){
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] !="*" && tokens[i] != "/" ){
                stk.push(stoi(tokens[i]));
            }
            else{
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if (tokens[i] == "+"){
                    res = (b+a);
                }
                else if (tokens[i] == "-"){
                    res = (b-a);
                }
                else if (tokens[i] == "*"){
                    res = (b*a);
                }
                else{
                    res = (b/a);
                }
                stk.push(res);
            }
        }
        res = stk.top();
        stk.pop();
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> tokens;
    string line;
    while (getline(cin, line)){
        if (line == "#"){
            break;
        }
        tokens.push_back(line);
    }
    RPN rpn;
    cout << rpn.evalRPN(tokens) << endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
