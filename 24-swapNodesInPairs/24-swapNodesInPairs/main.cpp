//
//  main.cpp
//  24-swapNodesInPairs
//
//  Created by Michael on 10/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        if (!head || !head->next) {
            return head;
        }
        ListNode* p = head;
        ListNode* q = head->next;
        p->next = swapPairs(q->next);
        q->next = p;
        return q;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
