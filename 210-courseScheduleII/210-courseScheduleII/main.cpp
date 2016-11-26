//
//  main.cpp
//  210-courseScheduleII
//
//  Created by Michael on 11/26/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    vector<int> findOrder(int numCourses, vector<pair<int,int>>& prerequisites){
        vector<unordered_set<int> > graph = makeGraph(numCourses, prerequisites);
        vector<bool> onPath(numCourses, false), visited(numCourses, false);
        vector<int> topoSort;
        for (int i=0; i<numCourses; i++){
            if (!visited[i] && dfsCycle(graph, onPath, visited, i, topoSort))
                return {};
        }
//        reverse(topoSort.begin(), topoSort.end());
        return topoSort;
    }
    
private:
    vector<unordered_set<int>> makeGraph(int num, vector<pair<int, int>>& prerequisites){
        vector<unordered_set<int>> graph(num);
        for (auto pre:prerequisites){
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }
    
    bool dfsCycle(vector<unordered_set<int>>& graph, vector<bool>& onPath, vector<bool>& visited, int node, vector<int>& topoSort){
        if (visited[node]) return false;
        topoSort.push_back(node);
        onPath[node] = visited[node] = true;
        for (int neigh:graph[node]){
            if (onPath[neigh] || dfsCycle(graph, onPath, visited, neigh, topoSort))
                return true;
        }
        onPath[node] = false;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
