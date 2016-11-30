//
//  main.cpp
//  223-rectangelArea
//
//  Created by Michael on 11/29/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
        int leftX = max(A, E);
        int leftY = max(B, F);
        int rightX = min(C, G);
        int rightY = min(D, H);
        if (leftX>rightX || leftY>rightY) return (C-A)*(D-B)+(G-E)*(H-F);
        return (C-A)*(D-B)+(G-E)*(H-F)-(rightY-leftY)*(rightX-leftX);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.computeArea(-2, -2, 2, 2, -1,4,1, 6) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
