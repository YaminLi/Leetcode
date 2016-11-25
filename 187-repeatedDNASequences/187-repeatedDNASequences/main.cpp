//
//  main.cpp
//  187-repeatedDNASequences
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<string> findRepeatedDnaSequence(string s){
        unordered_map<string, int> mp;
        for (int i=0; i+10-1<s.size(); i++){
            string subs = s.substr(i, 10);
            mp[subs]++;
        }
        vector<string> res;
        for (auto it=mp.begin(); it!=mp.end(); it++){
            if (it->second>=2) res.push_back(it->first);
        }
        return res;
    }
    
    vector<string> findRepeatedDnaSequence2(string s){
        unordered_map<string, int> mp;
        vector<string> res;
        for (int i=0; i+10-1<s.size();i++){
            string subs = s.substr(i, 10);
            if (!mp.count(subs)){
                mp[subs] = 1;
                for (int j=i+10; j+10-1<s.size(); j++){
                    string tmp = s.substr(j, 10);
                    if (mp.find(tmp) != mp.end() && mp[tmp] == 1){
                        mp[tmp]++;
                        res.push_back(tmp);
                    }
                }
//                if (mp[subs] == 1)
//                    mp.erase(subs);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<string > res = st.findRepeatedDnaSequence("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto s:res)
        cout << s << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
