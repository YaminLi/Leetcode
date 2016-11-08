//
//  main.cpp
//  58-lengthOfLastWord
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int lengthOfLastWord(string s){
        int count = 0;
        int i=s.size()-1;
        while (i>=0 && s[i] == ' ') {
            i--;
        }
        while (i>=0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.lengthOfLastWord("hello world");
//    std::cout << "Hello, World!\n";
    return 0;
}
