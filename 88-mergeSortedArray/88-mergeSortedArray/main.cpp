//
//  main.cpp
//  88-mergeSortedArray
//
//  Created by Michael on 11/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        if (n==0) return;
        if (m==0) {nums1 = nums2; return;}
        int i=m-1;
        int j=n-1;
        while (i>=0 && j>=0){
            nums1[i+j+1] = nums1[i] > nums2[j] ? nums1[i--]:nums2[j--];
        }
        while (j>=0){
            nums1[i+j+1] = nums2[j--];
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
