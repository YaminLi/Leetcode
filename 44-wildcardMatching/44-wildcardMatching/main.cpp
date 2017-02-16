//
//  main.cpp
//  44-wildcardMatching
//
//  Created by Michael on 2/16/17.
//  Copyright © 2017 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

bool isMatch(string s, string p){
    int sStar=-1, pStar=-1;
    int i=0, j=0;
    int n=p.size();
    for (; i<s.size(); ){
        if (j<n && (s[i]==p[j] || p[j]=='?')){
            i++;
            j++;
        }
        else if (j<n && p[j]=='*'){
            pStar = j++;
            sStar = i;
        }
        else if (pStar != -1){
            j = pStar+1;
            i = ++sStar;
        }
        else return false;
    }
    while (j<n && p[j]=='*') j++;
    return j==n;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << isMatch("aa", "a") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
