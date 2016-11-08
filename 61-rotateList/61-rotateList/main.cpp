//
//  main.cpp
//  61-rotateList
//
//  Created by Michael on 10/19/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        ListNode* nHead = new ListNode(0);
        nHead->next = head;
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast && k--) {
            fast = fast->next;
        }
        if (!fast) {
            return nHead->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* dummy = slow->next;
        slow->next = NULL;
        fast->next = nHead->next;
        nHead->next = dummy;
        return nHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for (int i=2; i<=5; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution st;
    head = st.rotateRight(head, 5);
    while (head->next) {
        cout << head->val << "->";
        head= head->next;
    }
    cout << head->val;
//    std::cout << "Hello, World!\n";
    return 0;
}
