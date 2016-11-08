//
//  main.cpp
//  4-medianSortedArrays
//
//  Created by Michael on 9/22/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



class Soluction{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
        int l1=nums1.size();
        int l2=nums2.size();
        int mid1 = l1/2;
        int mid2 = l2/2;
        if (l1==0) {
            return medOfSingle(nums2);
        }
        else if(l1==1){
            if (l2==1) {
                return m2(nums1[0], nums2[0]);
            }
            else if(l2%2){
                return m2(nums2[mid2], m3(nums1[0], nums2[mid2-1], nums2[mid2+1]));
            }
            else{
                return m3(nums2[mid2-1], nums2[mid2], nums1[0]);
            }
        }
        else if(l1 == 2) {
            if (l2==2) {
                return m4(nums1[0], nums1[1], nums2[0], nums2[1]);
            }
            else if(l2%2){
                return m3(nums2[mid2], max(nums1[0], nums2[mid2-1]), min(nums1[1], nums2[mid2+1]));
            }
            else{
                return m4(nums2[mid2], nums2[mid2-1], max(nums1[0], nums2[mid2-2]), min(nums1[1], nums2[mid2+1]));
            }
        }
        else{
            int idx1 = (l1-1)/2;
            int idx2 = (l2-1)/2;
            if (nums1[idx1] <= nums2[idx2]) {
                vector<int> tmp1;
                vector<int> tmp2;
                for (int i=idx1; i<l1; i++) {
                    tmp1.push_back(nums1[i]);
                }
                for (int i=0; i<l2-idx1; i++) {
                    tmp2.push_back(nums2[i]);
                }
                return findMedianSortedArrays(tmp1, tmp2);
            }
            else{
                vector<int> tmp1;
                vector<int> tmp2;
                for (int i=0; i<mid1+1; i++) {
                    tmp1.push_back(nums1[i]);
                }
                for (int i=idx1; i<l2; i++) {
                    tmp2.push_back(nums2[i]);
                }
                return findMedianSortedArrays(tmp1, tmp2);
            }
        }
    }
    
private:
    double medOfSingle(vector<int> &nums){
        int len =(int)nums.size();
        if(len==0)
            return -1;
        if(len%2)
            return nums[len/2];
        else
            return (nums[len/2]+nums[len/2-1])/2.0;
    }
    
    double m2(int num1, int num2){
        return (num1+num2)/2.0;
    }
    
    double m3(int n1, int n2, int n3){
        return n1+n2+n3-max(n1, max(n2, n3))-min(n1, min(n2, n3));
    }
    
    double m4(int n1, int n2, int n3, int n4){
        int Max = max(n1, max(n2, max(n3, n4)));
        int Min = min(n1, min(n2, min(n3, n4)));
        return (n1+n2+n3+n4-Max-Min)/2.0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums1={1, 2, 3, 6};
    vector<int> nums2={1, 1, 2, 3,5,6,9};
    Soluction s;
    cout << s.findMedianSortedArrays(nums1, nums2)<< endl;
//    std::cout << "Hello, World!\n";
    return 0;
}
