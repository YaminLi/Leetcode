//
//  main.cpp
//  43-multiplyStrings
//
//  Created by Michael on 10/16/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string multiply(string str1, string str2){
        string res;
        int carry = 0;
        int len1 = str1.size();
        int len2 = str2.size();
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        for (int i=0; i<len1+len2-1; i++) {
            int product = 0;
            for (int j=0; j<len2 && i-j>=0; j++) {
                if(i-j < len1)
                    product += (str2[j]-'0')*(str1[i-j]-'0');
            }
            product += carry;
            res.push_back(product%10 + '0');
            carry = product/10;
        }
        while(carry) {
            res.push_back(carry%10 + '0');
            carry = carry/10;
        }
        reverse(res.begin(), res.end());
        size_t pos = res.find_first_not_of('0');
        if (pos != string::npos) {
            return res.substr(pos);
        }
        return "0";
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.multiply("0", "125") << endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
