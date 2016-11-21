//
//  main.cpp
//  147-insertionSortList
//
//  Created by Michael on 11/12/16.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* nHead = new ListNode(0);
        nHead->next = head;
        ListNode* cur = head;
        ListNode* pre = nHead;
        while (cur){
            if (cur->next && cur->next->val < cur->val){
                while (pre->next && pre->next->val < cur->next->val)
                    pre = pre->next;
                ListNode* tmp = pre->next;
                //                ListNode* nxt = cur->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = tmp;
                pre= nHead;
            }
            else{
                cur = cur->next;
            }
        }
        return nHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next= new ListNode(3);
    p=p->next;
    p->next= new ListNode(2);
    p=p->next;
    p->next= new ListNode(4);
    Solution st;
    head = st.insertionSortList(head);
    while (head){
        cout << head->val << "->";
        head = head->next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}