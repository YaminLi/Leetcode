//
//  main.cpp
//  274-h-index
//
//  Created by Michael on 12/18/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int hIndex(vector<int>& citations){
        // counting sort
        if (citations.empty()) return 0;
        int n=citations.size();
        vector<int> cnt(n+1, 0);
        for (int i=0; i<n; i++){
            if (citations[i] >= n) cnt[n]++;
            else cnt[citations[i]]++;
        }
        
        int curCnt=0;
        for (int i=n; i>=0; i--){
            curCnt += cnt[i];
            if (curCnt >= i)
                return i;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << st.hIndex(citations) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
