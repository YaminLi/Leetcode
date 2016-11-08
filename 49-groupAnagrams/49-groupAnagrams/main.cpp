//
//  main.cpp
//  49-groupAnagrams
//
//  Created by Michael on 10/17/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

class Solution{
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> res;
        map<string, multiset<string>> myMap;
        for (int i=0; i<strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            myMap[t].insert(strs[i]);
        }
        
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            vector<string> tmp;
            for (auto its = it->second.begin(); its!=it->second.end(); its++) {
                tmp.push_back(*its);
            }
            res.push_back(tmp);
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
