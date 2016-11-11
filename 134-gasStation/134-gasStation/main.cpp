//
//  main.cpp
//  134-gasStation
//
//  Created by Michael on 11/10/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int n = gas.size();
        for (int i=0; i<n; ){
            int sum = 0;
            int j=i;
            for (; j<n+i; j++){
                sum += gas[j%n]-cost[j%n];
                if (sum < 0){
                    break;
                }
            }
            if (j == n+i)
                return i;
            else{
                i = j+1;
            }
        }
        return -1;
    }
    
    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost){
        int n=gas.size();
        for (int i=0; i<n; i++){
            int j=i;
            int sum1 = 0, sum2 = 0;
            for (; j<n+i; j++){
                sum1 += gas[j%n];
                sum2 += cost[j%n];
                if (sum1 < sum2){
                    break;
                }
            }
            if (j == n+i)
                return i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> gas = {4, 2, 3};
    vector<int> cost = {5, 3, 1};
    Solution st;
    cout << st.canCompleteCircuit(gas, cost)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
