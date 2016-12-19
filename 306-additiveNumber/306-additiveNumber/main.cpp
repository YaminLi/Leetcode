//
//  main.cpp
//  306-additiveNumber
//
//  Created by Michael on 12/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

bool isAdditiveNumber(string num) {
    int n=num.size();
    bool res;
    for (int len1=1; len1<=n-2; len1++){
        if (len1>1 && num[0] =='0') return false;
        long long num1 = stoll(num.substr(0, len1));
        for (int len2=1; len1+len2<=n-1; len2++){
            if (len2>1 && num[len1] == '0') break;
            long long num2 = stoll(num.substr(len1, len2));
            for (int len3=max(len1, len2); len1+len2+len3<=n; len3++){
                if (len3>1 && num[len1+len2]=='0') break;
                long long num3 = stoll(num.substr(len1+len2, len3));
                if (num3 == (num1+num2)){
                    if (len1+len2+len3 == n)
                        return true;
                    res = isAdditiveNumber(num.substr(len1));
                    if (res)
                        return true;
                }
                else if (num3 > (num1+num2))
                    break;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    if (isAdditiveNumber("199100199"))
        std::cout << "Hello, World!\n";
    return 0;
}
