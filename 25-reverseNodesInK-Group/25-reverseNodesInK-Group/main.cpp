//
//  main.cpp
//  25-reverseNodesInK-Group
//
//  Created by Michael on 10/7/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        if (!head || k == 1) {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = head;
        ListNode *cur = dummy;
        ListNode *nxt;
        int i=0;
        while (fast) {
            i++;
            fast = fast->next;
            if (i == k) {
                cur = slow->next;
                nxt = cur->next;
                while (--i) {
                    cur->next = nxt->next;
                    nxt->next = slow->next;
                    slow->next = nxt;
                    nxt = cur->next;
                }
                slow = cur;
            }
        }
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head = new ListNode(1);
    ListNode *nxt = head;
    for (int i=1; i<5; i++) {
        ListNode *p = new ListNode(i+1);
        nxt->next = p;
        nxt = nxt->next;
    }
    Solution st;
    ListNode *nH = st.reverseKGroup(head, 5);
    while (nH) {
        cout << nH->val << endl;
        nH = nH->next;
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
