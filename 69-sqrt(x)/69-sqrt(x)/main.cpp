//
//  main.cpp
//  69-sqrt(x)
//
//  Created by Michael on 10/21/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int mySqrt1(int x) {
        if(!x) return 0;
        int _x = x/2;
//        if(_x == 0) _x++;
        while(_x !=0 && x/_x < _x){
            _x = _x/2;
        }
        if (_x == 0) {
            _x++;
        }
        for(;;_x++){
            if(_x <= x/_x && (_x+1)> x/(_x+1))
                return _x;
        }
        return 0;
    }
    
    int mySqrt(int x){
        if (x <= 1) {
            return x;
        }
        int left = 0;
        int right = x/2+1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (mid <= x/mid && mid+1 > x/(mid+1)) {
                return mid;
            }
            else if (mid > x/mid)
                right = mid-1;
            else
                left = mid+1;
                
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.mySqrt(18) << endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
