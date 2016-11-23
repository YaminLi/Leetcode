//
//  main.cpp
//  155-minStack
//
//  Created by Michael on 11/23/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack{
private:
    stack<int> s;
    stack<int> minStack;
    
public:
    MinStack(){
        s = *new stack<int>;
        minStack = *new stack<int>;
    }
    
    void push(int x){
        s.push(x);
        if (minStack.empty() || x <= getMin())
            minStack.push(x);
    }
    
    void pop(){
        if (top() == getMin()) minStack.pop();
        s.pop();
    }
    
    int top(){
        return s.top();
    }
    
    int getMin(){
        return minStack.top();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    MinStack MS;
    MS.push(0);
    MS.push(1);
    MS.push(0);
    cout << MS.getMin() << endl;
    MS.pop();
    cout << MS.top() << endl;
    cout << MS.getMin() << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
