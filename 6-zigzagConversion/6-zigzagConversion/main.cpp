//
//  main.cpp
//  6-zigzagConversion
//
//  Created by Michael on 10/4/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string convert(string s, int numRows){
        string res;
        string *ps = new string[numRows];
        int idx = 0;
        int direction = 1;
        for (int i=0; i<s.size(); i++) {
            (*(ps+idx)).push_back(s[i]);
            if (idx  == numRows-1) {
                direction = -1;
            }
            else if(idx == 0){
                direction = 1;
            }
            idx += direction;
        }
        for (int i=0; i<numRows; i++) {
            res += *(ps+i);
        }
        delete []ps;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution st;
    string s;
    getline(cin, s);
    cout << st.convert(s, 3) << endl;
    return 0;
}
