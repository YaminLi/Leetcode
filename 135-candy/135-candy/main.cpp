//
//  main.cpp
//  135-candy
//
//  Created by Michael on 11/10/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int candy(vector<int>& ratings){
        int n=ratings.size();
        if (n<=1) return n;
        vector<int> cnt(n, 1);
        for (int i=1; i<n; i++){
            if (ratings[i] > ratings[i-1])
                cnt[i] = cnt[i-1]+1;
        }
        
        for (int i=n-1; i>0; i--){
            if (ratings[i-1] > ratings[i])
                cnt[i-1] = max(cnt[i]+1, cnt[i-1]);
        }
        int sum = 0;
        for (int i=0; i<n; i++)
            sum += cnt[i];
        return sum;
    }
    
    int candy1(vector<int>& ratings){
        int sum = 0;
        int n=ratings.size();
        if (n<=1) return n;
        vector<int> candy(n, 1);
        for (int i=1; i<n; i++){
            if (ratings[i] > ratings[i-1])
                candy[i] = candy[i-1]+1;
            else if (ratings[i] == ratings[i-1])
                candy[i] = 1;
            else
                candy[i] = candy[i-1]-1;
            if (i<n-1 && ratings[i] < ratings[i-1] && ratings[i] <= ratings[i+1])
                adjustCandy(ratings, candy, i);
        }
        if (ratings[n-1] < ratings[n-2]){
            adjustCandy(ratings, candy, n-1);
        }
        for (auto c:candy)
            sum += c;
        return sum;
    }
    
private:
    void adjustCandy(vector<int>& ratings, vector<int>& candy, int idx){
        int diff = 1- candy[idx];
        int k = idx;
        while (k>0 && ratings[k-1] > ratings[k]){
            candy[k] += diff;
            k--;
        }
        if (diff >0 ) candy[k] += diff;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<int> a = {1,3,5,4};
    cout << st.candy1(a) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
