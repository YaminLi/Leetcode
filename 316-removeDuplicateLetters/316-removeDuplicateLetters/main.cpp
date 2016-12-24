//
//  main.cpp
//  316-removeDuplicateLetters
//
//  Created by Michael on 12/23/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

string removeDuplicateLetters(string s) {
    int m[256]={0}, visited[256]={0};
    string res = "0";
    for (auto c:s)
        m[c]++;
    
    for (auto c:s){
        m[c]--;
        if (visited[c]) continue;
        while (c < res.back() && m[res.back()]){
            visited[res.back()] = 0;
            res.pop_back();
        }
        res += c;
        visited[c] = 1;
    }
    return res.substr(1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << removeDuplicateLetters("cbacb") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
