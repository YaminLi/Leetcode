//
//  main.cpp
//  204-countPrimes
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int countPrimes(int n){
        vector<bool> isPrime(n, true);
        for (int i=2; i*i<n; i++){
            if (!isPrime[i]) continue;
            for (int j=i*i; j<n; j+=i){
                isPrime[j] = false;
            }
        }
        int cnt=0;
        for (int i=2; i<n; i++)
            if (isPrime[i]) cnt++;
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    cout << st.countPrimes(10) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
