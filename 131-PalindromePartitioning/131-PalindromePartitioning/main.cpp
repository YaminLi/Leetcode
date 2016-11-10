//
//  main.cpp
//  131-PalindromePartitioning
//
//  Created by Michael on 11/9/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<string>> partition(string s){
        vector<vector<string> > res;
        if (s.empty()) return res;
        int n=s.size();
        if ( n==1 ) {
            res.push_back(*new vector<string>{s});
            return res;
        }
        for (int len=1; len<=n; len++){
            string subs = s.substr(0, len);
            if (isPalin(subs)){
                if (len <n){
                    vector<vector<string>> tmp = partition(s.substr(len));
                    for (int i=0; i<tmp.size(); i++){
                        reverse(tmp[i].begin(), tmp[i].end());
                        tmp[i].push_back(subs);
                        reverse(tmp[i].begin(), tmp[i].end());
                        res.push_back(tmp[i]);
                    }
                }
                else{
                    res.push_back(*new vector<string>{subs});
                }
            }
        }
        return res;
    }
    
private:
    bool isPalin(string s){
        int left=0;
        int right=s.size()-1;
        while (left <= right){
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<vector<string> > res = st.partition("bb");
    for (int i=0; i<res.size(); i++){
        for (int j=0; j<res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
