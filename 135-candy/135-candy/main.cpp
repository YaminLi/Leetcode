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
        int sum = 0;
        int n=ratings.size();
        for (int i=0; i<n; ){
            int cnt = 1;
            int j=i;
            while (j<n-1 && ratings[j] > ratings[j+1]){
                j++;
                cnt++;
            }
            sum += (cnt+1)*cnt/2;
            i = j;
            while (j<n-1&& ratings[j] < ratings[j+1]){
                j++;
                cnt++;
            }
            sum += (cnt+1)*cnt/2;
            i++;
        }
        for (int i=0; i<n; ){
            int cnt = 0;
            while (i<n-1 && ratings[i] < ratings[i+1]){
                i++;
                cnt++;
            }
            sum += (cnt+1)*cnt/2;
            i++;
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution st;
    vector<int> a = {1,3,5,4};
    cout << st.candy(a) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
