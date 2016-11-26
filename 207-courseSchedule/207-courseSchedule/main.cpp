//
//  main.cpp
//  207-courseSchedule
//
//  Created by Michael on 11/25/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites){
        if (prerequisites.empty()) return true;
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        for (int i=0; i<numCourses; i++){
            if (!visited[i] && dfsCycle(graph, onpath, visited, i))
                return false;
        }
        return true;
    }
    
private:
    vector<unordered_set<int> > makeGraph(int num, vector<pair<int, int> > & prerequisites){
        vector<unordered_set<int>> graph(num);
        for (auto pre:prerequisites){
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }
    
    bool dfsCycle(vector<unordered_set<int>>& graph, vector<bool>& onpath, vector<bool>& visited, int node){
        if (visited[node]) return false;
        onpath[node] = visited[node] = true;
        for (int neigh:graph[node]){
            if (onpath[neigh] || dfsCycle(graph, onpath, visited, neigh))
                return true;
        }
        onpath[node] = false;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
