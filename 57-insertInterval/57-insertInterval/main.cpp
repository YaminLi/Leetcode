//
//  main.cpp
//  57-insertInterval
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0){}
    Interval(int s, int e): start(s), end(e) {}
};

class Solution{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.empty()){
            res.push_back(newInterval);
            return res;
        }
        int i=0;
        for(; i<intervals.size() && intervals[i].end < newInterval.start; i++){
            res.push_back(intervals[i]);
        }
        for(; i<intervals.size() && intervals[i].start <= newInterval.end; i++){
            Interval tmp(min(newInterval.start, intervals[i].start), max(newInterval.end, intervals[i].end));
            newInterval = tmp;
        }
        res.push_back(newInterval);
        for(; i<intervals.size(); i++){
            res.push_back(intervals[i]);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<Interval> a;
    Interval tmp = Interval(1, 5);
    a.push_back(tmp);
//    tmp = Interval(3, 5);
//    a.push_back(tmp);
//    tmp = Interval(6, 7);
//    a.push_back(tmp);
//    tmp = Interval(8, 10);
//    a.push_back(tmp);
//    tmp = Interval(12, 16);
//    a.push_back(tmp);
    Solution st;
    vector<Interval> res = st.insert(a, Interval(0,0));
    for (int i=0; i<res.size(); i++) {
        cout << res[i].start << " " << res[i].end << endl;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
