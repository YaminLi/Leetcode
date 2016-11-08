//
//  main.cpp
//  19-removeNthNodeFromEndOfList
//
//  Created by Michael on 10/6/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        ListNode* p =head;
        int len=0;
        while (p) {
            p=p->next;
            len++;
        }
        p = dummy;
        int i=0;
        while (i<len-n) {
            p=p->next;
            i++;
        }
        p->next = p->next->next;
        return dummy->next;
    }
    
    ListNode* removeNthFromEnd2(ListNode* head, int n){
        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        int i=0;
        while (i<=n) {
            fast = fast->next;
            i++;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head=new ListNode(1);
    ListNode *p = head;
    for (int i=2; i<=5; i++) {
        ListNode *q = new ListNode(i);
        p->next = q;
        p = q;
    }
    p->next = NULL;
    Solution st;
    p = st.removeNthFromEnd2(head, 2);
    while (p) {
        cout << p->val<< endl;
        p=p->next;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
