//
//  main.cpp
//  313-superUglyNumber
//
//  Created by Michael on 12/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    int k=primes.size();
    vector<int> idx(k, 0);
    vector<int> res(n);
    res[0] = 1;
    for (int i=1; i<n; i++){
        int curMin=INT_MAX;
        for (int j=0; j<k; j++){
            curMin = min(curMin, res[idx[j]]*primes[j]);
        }
        res[i] = curMin;
        for (int j=0; j<k; j++){
            if (curMin == res[idx[j]]*primes[j])
                idx[j]++;
        }
    }
    return res[n-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> primes = {2, 3, 5};
    cout << nthSuperUglyNumber(10, primes) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
