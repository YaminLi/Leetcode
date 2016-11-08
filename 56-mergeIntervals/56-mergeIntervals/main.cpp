//
//  main.cpp
//  56-mergeIntervals
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

struct comp{
    bool operator() (const Interval a, const Interval b){
        return a.start < b.start;
    }
};

class Solution {
public:
    
    vector<Interval> merge(vector<Interval>& intervals){
        vector<Interval> res;
        if (intervals.empty()) {
            return res;
        }
        comp myComp;
        sort(intervals.begin(), intervals.end(), myComp);
        res.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i].start <= res.back().end) {
                res.back().end = max(res.back().end, intervals[i].end);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<Interval> a;
    Interval tmp = Interval(1, 3);
    a.push_back(tmp);
    tmp = Interval(2, 6);
    a.push_back(tmp);
    tmp = Interval(8, 10);
    a.push_back(tmp);
    tmp = Interval(15, 18);
    a.push_back(tmp);
    Solution st;
    vector<Interval> res = st.merge(a);
    for (int i=0; i<res.size(); i++) {
        cout << res[i].start << " " << res[i].end << endl;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
