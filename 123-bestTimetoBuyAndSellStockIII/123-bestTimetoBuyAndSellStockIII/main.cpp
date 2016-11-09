//
//  main.cpp
//  123-bestTimetoBuyAndSellStockIII
//
//  Created by Michael on 11/8/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int buy1=INT_MIN;
        int sale1=0;
        int buy2=INT_MIN;
        int sale2=0;
        for (int i=0; i<prices.size(); i++){
            buy1 = max(buy1, -prices[i]);
            sale1 = max(sale1, prices[i]+buy1);
            buy2 = max(buy2, sale1-prices[i]);
            sale2 = max(sale2, prices[i]+buy2);
        }
        return sale2;
    }
    
    int maxProfit1(vector<int>& prices){
        int n = prices.size();
        vector<int> left(n);
        int maxProfit = 0;
        int minPrices = INT_MAX;
        for (int i=0; i<n; i++){
            minPrices = min(minPrices, prices[i]);      // 更新最小买入价
            maxProfit = max(maxProfit, prices[i]-minPrices); // i的最大利润为（i-1的利润）和（当前卖出价和之前买入价之差）的较大那个
            left[i] = maxProfit;
        }
        vector<int> right(n);
        maxProfit = 0;
        int maxPrices = INT_MIN;
        for (int i=n-1; i>=0; i--){
            maxPrices = max(maxPrices, prices[i]);   // 更新最高卖出价
            maxProfit = max(maxProfit, maxPrices-prices[i]); // i的最大利润为（i+1的利润）和（最高卖出价和当前买入价之差）的较大那个
            right[i] = maxProfit;
        }
        maxProfit = 0;
        for(int i=0; i<n; i++){
            maxProfit = max(maxProfit, left[i]+right[i]);
        }
        return maxProfit;
    }
    
    int maxProfit2(vector<int>& prices){
        int maxProfit = 0;
        for(int i=0; i<prices.size(); i++){
            int profit1 = 0;
            int minPrices = INT_MAX;
            for(int j=0; j<i; j++){
                minPrices = min(minPrices, prices[j]);
                profit1 = max(profit1, prices[j]-minPrices);
            }
            int profit2 = 0;
            minPrices = INT_MAX;
            for(int j=i; j<prices.size(); j++){
                minPrices = min(minPrices, prices[j]);
                profit2 = max(profit2, prices[j]-minPrices);
            }
            maxProfit = max(maxProfit, profit1+profit2);
        }
        return maxProfit;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,4,2,5,7,2,4,9,0};
    Solution st;
    cout << st.maxProfit(a) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
