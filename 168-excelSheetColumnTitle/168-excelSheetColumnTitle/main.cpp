//
//  main.cpp
//  168-excelSheetColumnTitle
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    string convertToTitle(int n){
        if (n<=0) return "";
        string res;
        string alpha[26] = {"A", "B", "C", "D", "E", "F", "G",
                            "H", "I", "J", "K", "L", "M", "N",
                            "O", "P", "Q", "R", "S", "T",
                            "U", "V", "W", "X", "Y", "Z"};
        while (n){
            res.insert(0, alpha[(n-1)%26]);
            n = (n-1)/26;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.convertToTitle(26) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
