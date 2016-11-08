//
//  main.cpp
//  89-grayCode
//
//  Created by Michael on 11/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> grayCode(int n){
        if (n==0)
            return *new vector<int>;
        if (n==1){
            return *new vector<int>{0, 1};
        }
        vector<int> res = grayCode(n-1);
        vector<int> resN;
        for (int i:res){
            resN.push_back(i);
        }
        for (int i=res.size()-1; i>=0; i--){
            resN.push_back(res[i]+ (1<<(n-1)));
        }
        return resN;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<int> res = st.grayCode(2);
    for (auto i: res){
        cout << i << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
