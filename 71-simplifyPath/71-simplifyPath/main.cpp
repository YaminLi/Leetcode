//
//  main.cpp
//  71-simplifyPath
//
//  Created by Michael on 10/23/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
public:
    string simplifyPath(string path){
        string res;
        if (path.empty()) {
            return res;
        }
        stack<string> s;
        int start=-1;
        int end=-1;
        for (int i=0; i<path.size();) {
            if (path[i] == '/') {
                start = i;
                for (i=start+1; i<path.size(); i++) {
                    if (i+1 == path.size()) {
                        end = (path[i]=='/' ? i:i+1);
                        i++;
                        break;
                    }
                    if (path[i] == '/') {
                        end = i;
                        break;
                    }
                }
                string tmp = path.substr(start+1, end-start-1);
                if (tmp.empty() || tmp == "." || (tmp == ".." && s.empty())) {
                    continue;
                }
                else if (tmp == ".." && !s.empty()){
                    s.pop();
                }
                else{
                    s.push(tmp);
                }
            }
        }
        while (!s.empty()) {
            res.insert(0, s.top());
            res.insert(0, "/");
            s.pop();
        }
        return res.empty()? "/" : res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.simplifyPath("/.") << endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
