//
//  main.cpp
//  67-addBinary
//
//  Created by Michael on 10/20/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    string addBinary(string a, string b){
        int m = a.size();
        int n = b.size();
        if (m < n) {
            return addBinary(b, a);
        }
        int carry = 0;
        string res;
        int i;
        for (i=n-1; i>=0; i--) {
            int sum = a[i]-'0' + b[i]-'0' + carry;
            res.push_back(sum%2 + '0');
            carry = sum/2;
        }
        for (i=m-1; i>=m-n; i--) {
            int sum = a[i]-'0' + carry;
            res.push_back(sum%2 + '0');
            carry = sum/2;
        }
        if (carry) {
            res.push_back(carry+'0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.addBinary("11", "1") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
