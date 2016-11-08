//
//  main.cpp
//  66-plusOne
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        int n = digits.size();
        for (int i=n-1; i>=0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else{
                digits[i] += 1;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
