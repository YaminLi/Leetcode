//
//  main.cpp
//  166-fractionToRecurringDecimal
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
public:
    string fractionToDecimal(int numerator, int denominator){
        if (numerator == 0) return "0";
        string res;
        if (numerator<0 ^ denominator<0) res+= "-";
        //转化为正数，INT_MIN转化为正数会溢出，故用long long。long long int n=abs(INT_MIN)得到的n仍然是负的，所以写成下面的形式。
        long long n=numerator, d=denominator;
        n=abs(n), d=abs(d);
        
        res+= to_string(n/d);
        long long r=n%d;
        if (r==0) return res;
        else res+=".";
        unordered_map<int, int> mp;
        while (r){
            if (mp.find(r) != mp.end()){
                res.insert(mp[r],"(");
                res+= ")";
                break;
            }
            mp[r] = res.size();
            r*=10;
            res += to_string(r/d);
            r = r%d;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.fractionToDecimal(2, 1)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
