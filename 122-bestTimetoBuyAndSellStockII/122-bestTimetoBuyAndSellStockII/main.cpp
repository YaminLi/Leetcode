//
//  main.cpp
//  122-bestTimetoBuyAndSellStockII
//
//  Created by Michael on 11/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        int profit = 0;
        for (int i=0; i<prices.size(); i++){
            while (i<n-1 && prices[i] >= prices[i+1])
                i++;
            int valley = prices[i];
            while (i<n-1 && prices[i] <= prices[i+1])
                i++;
            int peak = prices[i];
            profit += (peak-valley);
        }
        return profit;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {7, 1, 5, 3, 6, 4};
    Solution st;
    cout << st.maxProfit(a) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
