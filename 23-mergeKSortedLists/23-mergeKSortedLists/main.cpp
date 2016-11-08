//
//  main.cpp
//  23-mergeKSortedLists
//
//  Created by Michael on 10/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

struct comp{
    bool operator()(const ListNode* l1, const ListNode* l2){
        return l1->val > l2->val;
    }
};

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode *nHead=new ListNode(0);
        for (int i=0; i<lists.size(); i++) {
            if(lists[i]) pq.push(lists[i]);
        }
        ListNode* p = nHead;
        while(!pq.empty()){
            ListNode* nxt = pq.top();
            p->next = nxt;
            p = p->next;
            pq.pop();
            if(nxt->next) pq.push(nxt->next);
        }
        return nHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
