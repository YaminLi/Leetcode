//
//  main.cpp
//  1-twoSum
//
//  Created by Michael on 9/20/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream infile("/Users/Michael/Documents/Code/c++/leetcode/input.txt");
    string line;
    int count = 1;
    vector<int> nums;
    int target=0;
    while (getline(infile, line)) {
        if(count%2){
            char *pch;
            char *dup = strdup(line.c_str());
            pch = strtok(dup, " ");
            free(dup);
            while (pch != NULL) {
//                cout << pch << endl;
                nums.push_back(stoi(strdup(pch)));
                pch = strtok(NULL, " ");
            }
        }
        else{
            target = stoi(line);
            cout << target << endl;
            map<int, int> myMap;
            int idx1 = 0;
            int idx2 = 0;
            for (int i=0; i<nums.size(); i++) {
                int tmp = target - nums[i];
                auto it = myMap.find(tmp);
                if (it != myMap.end()) {
                    idx2 = i;
                    idx1 = it->second;
                }
                else{
                    myMap[nums[i]] = i;
                }
            }
            cout << idx1 << " " << idx2 << endl;
            nums.clear();
        }
        count++;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}

