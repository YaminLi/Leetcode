//
//  main.cpp
//  86-partitionList
//
//  Created by Michael on 11/5/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v):val(v), next(NULL){}
};

class Solution{
public:
    ListNode* partition(ListNode* head, int x){
        ListNode* lessHead = new ListNode(0);
        ListNode* largeHead = new ListNode(0);
        ListNode *lessCur=lessHead, *largeCur=largeHead;
        while (head){
            if (head->val < x){
                lessCur->next = head;
                lessCur = lessCur->next;
            }
            else{
                largeCur->next = head;
                largeCur = largeCur->next;
            }
            head = head->next;
        }
        largeCur->next = NULL;
        lessCur->next = largeHead->next;
        return lessHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head=new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(2);
    Solution st;
    head = st.partition(head, 3);
    while (head){
        cout << head->val <<  "->";
        head = head->next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
