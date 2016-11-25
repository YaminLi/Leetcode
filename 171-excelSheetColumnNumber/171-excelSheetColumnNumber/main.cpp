//
//  main.cpp
//  171-excelSheetColumnNumber
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int titleToNumber(string s){
        int res=0;
        if (s.empty()) return res;
        for (int i=0; i<s.size(); i++){
            res=res*26+(s[i]-'A'+1);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.titleToNumber("AB") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
