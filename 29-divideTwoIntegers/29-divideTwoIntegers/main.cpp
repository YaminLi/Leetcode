//
//  main.cpp
//  29-divideTwoIntegers
//
//  Created by Michael on 10/7/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <climits>

using namespace std;

class Solution{
public:
    int divide(int divident, int divisor){
        if (!divisor || (divident==INT_MIN && divisor==-1)) {
            return INT_MAX;
        }
        int sign = (divident<0)^(divisor<0)?-1:1;
        unsigned long dvd = abs((long)divident);
        unsigned long dvs = abs((long)divisor);
        int res = 0;
        while (dvs <= dvd) {
            long tmp = dvs;
            int i = 1;
            while (dvd >= tmp<<i) {
                i++;
            }
            dvd -= tmp<<(i-1);
            res += 1<<(i-1);
        }
        return sign==1? res: -res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.divide(10, 3);
//    std::cout << "Hello, World!\n";
    return 0;
}
