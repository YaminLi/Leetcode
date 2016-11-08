//
//  main.cpp
//  92-reverseLinkedListII
//
//  Created by Michael on 11/6/16.
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
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if (m==n) return head;
        ListNode* nHead = new ListNode(0);
        nHead->next = head;
        int i=1;
        ListNode* p = head;
        ListNode* pre = nHead;
        while (i<m){
            p = p->next;
            pre = pre->next;
            i++;
        }
        ListNode* q =p->next;
        ListNode* r = q;
        while (i<n){
            r = q->next;
            q->next = p;
            p = q;
            q=r;
            i++;
        }
        pre->next->next = r;
        pre->next = p;
        return nHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    int i=2;
    while (i<=5){
        p->next = new ListNode(i);
        p = p->next;
        i++;
    }
    Solution st;
    head = st.reverseBetween(head, 2, 4);
    while (head){
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
