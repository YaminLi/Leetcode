//
//  main.cpp
//  328-Odd Even Linked List
//
//  Created by Michael on 1/12/17.
//  Copyright © 2017 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* cur = head->next->next;
    ListNode* evenHead = head->next;
    ListNode* oddCur = head;
    ListNode* evenCur = evenHead;
    int i=3;
    while (cur){
        if (i%2){
//            cout << cur->val << endl;
            oddCur->next = cur;
            oddCur = oddCur->next;
        }
        else{
            evenCur->next = cur;
            evenCur = evenCur->next;
        }
        cur = cur->next;
        i++;
    }
    evenCur->next = NULL;
    oddCur->next = evenHead;
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head = new ListNode(1);
    ListNode* p=head;
    for (int i=2; i<=8; i++){
        p->next = new ListNode(i);
        p = p->next;
    }
    p = oddEvenList(head);
    while (p){
        cout << p->val << "->";
        p = p->next;
    }
    
    cout << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
