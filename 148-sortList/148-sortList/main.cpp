//
//  main.cpp
//  148-sortList
//
//  Created by Michael on 11/21/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(NULL){}
};

class Solution{
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* nHead = new ListNode(0);
        nHead->next = head;
        ListNode* slow = nHead;
        ListNode* fast = nHead;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mergeSort(sortList(head), sortList(mid));
    }
    
private:
    ListNode* mergeSort(ListNode* head1, ListNode* head2){
        ListNode* nHead = new ListNode(0);
        ListNode* cur = nHead;
        while (head1 && head2){
            if (head1->val < head2->val){
                cur->next = head1;
                cur = cur->next;
                head1 = head1->next;
            }
            else{
                cur->next = head2;
                cur = cur->next;
                head2 = head2->next;
            }
        }
        if (head1) cur->next = head1;
        else if (head2) cur->next = head2;
        return nHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
