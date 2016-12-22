//
//  main.cpp
//  301-removeInvalidParentheses
//
//  Created by Michael on 12/21/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void remove(string s, vector<string>& res, int begin, int last, char par[]){
    for (int stack=0, i=begin; i<s.size(); i++){
        if (s[i] == par[0]) stack++;
        if (s[i] == par[1]) stack--;
        if (stack >= 0) continue;
        for (int j=last; j<=i; j++){
            if (s[j] == par[1] && (j==last || s[j-1] != par[1]))
                remove(s.substr(0, j)+s.substr(j+1), res, i, j, par);
        }
        return ;
    }
    
    string reverseS = s;
    reverse(reverseS.begin(), reverseS.end());
    if (par[0] == '(')
        remove(reverseS, res, 0, 0, new char[2]{')', '('});
    else{
        res.push_back(reverseS);
    }
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    remove(s, res, 0, 0, new char[2]{'(', ')'});
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> res = removeInvalidParentheses(")(");
    for (auto s:res){
        cout << s << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
