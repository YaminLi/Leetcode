//
//  main.cpp
//  91-decodeWays
//
//  Created by Michael on 11/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Solution{
public:
    int numDecodings(string s){
        if (s.empty()) return 0;
        if (s.size() == 1 && s[0] != '0') return 1;
        if (s.size() >= 1 && s[0] == '0') return 0;
        if (s[0] == '1' || (s[0] =='2' && (s[1]>='0' && s[1] <= '6') )){
            string tmp = s.substr(2);
            if (tmp.empty()){
                return numDecodings(s.substr(1))+1;
            }
            else{
                return numDecodings(s.substr(1))+numDecodings(s.substr(2));
            }
        }
        return numDecodings(s.substr(1));
    }
    
    int numDecodings2(string s){
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> res(n, 0);
        if (s[0] != '0') res[0] = 1;
        else return 0;
        for (int i=1; i<n; i++){
            if ((s[i-1] == '1' && s[i] != '0') || (s[i-1] == '2' && (s[i] >= '1' && s[i] <= '6'))){
                if (i==1){
                    res[i] = res[i-1]+1;
                }
                else{
                    res[i] = res[i-1]+res[i-2];
                }
            }
            else if ((s[i-1] == '0' || s[i-1] >= '3') && s[i] == '0'){
                return 0;
            }
            else if ((s[i-1] == '1' || s[i-1] == '2') && s[i] == '0'){
                if (i==1)
                    res[i] = 1;
                else
                    res[i] = res[i-2];
            }
            else{
                res[i] = res[i-1];
            }
        }
        return res[n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    clock_t start1, start2;
    double duration;
    start1 = clock();
    cout << st.numDecodings("1168963884134125126536966946586868418993819971673459188478711546479621135253876271366851168524933185") << endl;
    duration = (clock()-start1)/(double)CLOCKS_PER_SEC;
    cout << "method1: "<< duration << endl;
    start2 = clock();
    cout << st.numDecodings2("1168963884134125126536966946586868418993819971673459188478711546479621135253876271366851168524933185") << endl;
    duration = (clock()-start2)/(double)CLOCKS_PER_SEC;
    cout << "method2: "<< duration << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
