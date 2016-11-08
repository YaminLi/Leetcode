//
//  main.cpp
//  83-removeDuplicatesFromSortedList
//
//  Created by Michael on 11/5/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(NULL){}
};

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* nHead = new ListNode(0);
        nHead->next = head;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        while (nxt){
            while (nxt && nxt->val == cur->val){
                nxt = nxt->next;
            }
            if (nxt == cur->next){
                cur = nxt;
            }
            else{
                cur->next = nxt;
                cur = nxt;
            }
            if (nxt) nxt = nxt->next;
        }
        return nHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head =  new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(3);
    Solution st;
    head = st.deleteDuplicates(head);
    while (head) {
        cout << head->val << "->";
        head =  head->next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
