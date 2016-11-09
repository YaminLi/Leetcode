//
//  main.cpp
//  121-bestTimeToBuyAndSellStock
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
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (int i=0; i<prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << st.maxProfit(a) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
