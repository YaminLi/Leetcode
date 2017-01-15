//
//  main.cpp
//  331-verifyPreorderSerializationofaBT
//
//  Created by Michael on 1/12/17.
//  Copyright © 2017 Michael. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

bool isValidSerialization(string preorder) {
    if (preorder.empty()) return false;
    stringstream ss(preorder);
    string node;
    stack<string> stk;
    while (getline(ss, node, ',')){

        while (node=="#" && !stk.empty() && stk.top() == "#"){
            stk.pop();
            if (stk.empty()) return false;
                stk.pop();
        }
        stk.push(node);
    }
    return stk.size()==1 && stk.top()=="#";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    if (isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#")){
        std::cout << "Hello, World!\n";
    }
    return 0;
}
