//
//  main.cpp
//  8-atoi
//
//  Created by Michael on 10/4/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <climits>

using namespace std;

class Solution{
public:
    int myAtoi(string s){
        long res = 0;
        int i=0;
        while (s.at(i) == ' ')
            i++;
        int sign=1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(s[i]=='+'){
            sign = 1;
            i++;
        }
        while ((s[i]>= '0' && s[i]<='9') && i<s.size()) {
            res = res*10+ (int)(s[i]-'0');
            if (sign*res > INT_MAX) return INT_MAX;
            else if(sign*res < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)res*sign;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    string s;
    getline(cin, s);
    cout << s << endl;
    std::cout << st.myAtoi(s)<< endl;
    return 0;
}
