//
//  main.cpp
//  48-rotateImage
//
//  Created by Michael on 10/17/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void rotate(vector<vector<int>>& img){
        reverse(img.begin(), img.end());
        for (int i=0; i<img.size(); i++) {
            for (int j=i+1; j<img[i].size(); j++) {
                swap(img[i][j], img[j][i]);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
//    reverse(a.begin(), a.end());
    Solution st;
    st.rotate(a);
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
