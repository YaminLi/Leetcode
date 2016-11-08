//
//  main.cpp
//  2-AddTwoNumbers
//
//  Created by Michael on 9/21/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
}Node, *pNode;

class linkedList{
private:
    pNode head;
    
public:
    linkedList(){
        this->head = NULL;
    }
    
    ~linkedList(){
        pNode tmp = head->next;
        delete head;
        head = tmp;
    }
    
    pNode add(int x){
        if (head == NULL) {
            head = new Node;
            head->val = x;
            
        }
        else{
            pNode tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            pNode nNode = new Node;
            nNode->val = x;
            nNode->next = NULL;
            tmp->next = nNode;
        }
        return head;
    }
    
    void print(pNode head){
        pNode p=head;
        while (p != NULL) {
            std::cout << p->val << " ";
            p = p->next;
        }
    };
};

class Solution{
public:
    pNode addTwoNumbers(pNode l1, pNode l2){
        linkedList l;
        pNode nNode=NULL;
        int carry = 0;
        while (l1 && l2) {
            nNode = l.add((l1->val+l2->val+carry)%10);
            carry = (l1->val+l2->val+carry)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            nNode = l.add((l1->val+carry)%10);
            carry = (l1->val+carry)/10;
            l1 = l1->next;
        }
        while (l2) {
            nNode = l.add((l2->val+carry)%10);
            carry = (l2->val+carry)/10;
            l2 = l2->next;
        }
        if (carry) {
            nNode = l.add(carry);
        }
        return nNode;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    linkedList list1;
    pNode head1=NULL;
    for (int i=0; i<6; i++) {
        head1 = list1.add(i);
    }
    list1.print(head1);
    cout << endl;
    
    linkedList list2;
    pNode head2=NULL;
    for (int i=0; i<6; i++) {
        head2 = list2.add(i);
    }
    list2.print(head2);
    cout << endl;
    
    Solution myS;
    pNode nHead = myS.addTwoNumbers(head1, head2);
    list2.print(nHead);
    cout << endl;
//    ListNode
    std::cout << "Hello, World!\n";
    return 0;
}
