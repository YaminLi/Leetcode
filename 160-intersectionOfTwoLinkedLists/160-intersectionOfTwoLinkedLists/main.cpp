//
//  main.cpp
//  160-intersectionOfTwoLinkedLists
//
//  Created by Michael on 11/24/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(NULL) {}
};

class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        if (!headA || !headB) return NULL;
        ListNode* p = headA;
        ListNode* q = headB;
        while (p && q && p != q){
            p = p->next;
            q = q->next;
            if (!p) p = headB;
            if (!q) q = headA;
        }
        return p;
    }
    
    ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB){
        int lenA=0, lenB=0;
        ListNode* p=headA;
        ListNode* q=headB;
        while (p){
            p=p->next;
            lenA++;
        }
        while (q){
            q=q->next;
            lenB++;
        }
        if (lenA<lenB){
            p=headB;
            q=headA;
            swap(lenA, lenB);
        }
        else{
            p=headA;
            q=headB;
        }
        while (lenA>lenB){
            p = p->next;
            lenA--;
        }
        while (p && q){
            if (p==q) return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* headA = new ListNode(1);
    ListNode* headB = new ListNode(2);
    ListNode* p=headA;
    ListNode* q=headB;
    p->next = new ListNode(2);
    p=p->next;
    p->next = new ListNode(3);
    p=p->next;
    q->next = new ListNode(3);
    q=q->next;
    p->next = new ListNode(4);
    p=p->next;
    q->next = p;
    q=q->next;
    p->next = new ListNode(5);
    p=p->next;
    p->next= new ListNode(6);
    
    Solution st;
    p = st.getIntersectionNode(headA, headB);
    cout << p->val << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
