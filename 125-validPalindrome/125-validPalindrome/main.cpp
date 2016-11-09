//
//  main.cpp
//  125-validPalindrome
//
//  Created by Michael on 11/9/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <ctype.h>

using namespace std;

class Solution{
public:
    bool isPalindrome(string s){
        int left=0;
        int right=s.size()-1;
        while (left <= right){
            while (!isalnum(s[left]) && left < right)
                left++;
            while (!isalnum(s[right]) && right > left)
                right--;
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    if (st.isPalindrome("A man, a plan, a canal: Panama"))
        std::cout << "Hello, World!\n";
    return 0;
}
