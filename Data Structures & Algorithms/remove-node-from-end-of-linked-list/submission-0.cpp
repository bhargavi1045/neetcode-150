/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(n && fast){
            fast=fast->next;
            n--;
        }
        ListNode* prev=NULL;
        while(fast){
           prev=slow;
           slow=slow->next;
           fast=fast->next;
        }
        
        if(!prev) return head->next;
        prev->next=slow->next;
        return head;
    }
};
