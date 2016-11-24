//
//  main.cpp
//  149-maxPointsOnALine
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point{
    int x;
    int y;
    Point(): x(0), y(0){}
    Point(int a, int b): x(a), y(b) {}
};

class Solution{
public:
    int maxPoints(vector<Point>& points){
        if (points.empty()) return 0;
        int maxPts = 0;
        for (int i=0; i<points.size(); i++){
            unordered_map<float, int> slopeCnt;
            int curMax=0, nInf=0, nSame=0;
            for (int j=i+1; j<points.size(); j++){
                if (points[j].x == points[i].x){
                    if (points[j].y == points[i].y)
                        nSame++;
                    else
                        nInf++;
                }
                else{
                    float slope = (float)(points[j].y-points[i].y)/(float)(points[j].x-points[i].x);
                    slopeCnt[slope]++;
                    curMax = max(curMax, slopeCnt[slope]);
                }
            }
            curMax = max(curMax, nInf)+nSame+1;
            maxPts = max(maxPts, curMax);
        }
        return maxPts;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
