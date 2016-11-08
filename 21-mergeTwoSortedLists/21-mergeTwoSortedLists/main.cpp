//
//  main.cpp
//  21-mergeTwoSortedLists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while (l1 || l2) {
            if (!l1) {
                p->next = l2;
                l2 = l2->next;
            }
            else if (!l2) {
                p->next = l1;
                l1 = l1->next;
            }
            else{
                if (l1->val < l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                }
                else{
                    p->next = l2;
                    l2 = l2->next;
                }
            }
            p=p->next;
        }
        return dummy->next;
    }
    
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        }
        else if(!l2){
            return l1;
        }
        else{
            if(l1->val < l2->val){
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else{
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    ListNode* head1 = new ListNode(1);
//    ListNode* head2
    std::cout << "Hello, World!\n";
    return 0;
}
