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
    ListNode* findMiddleNode(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* middleNode=findMiddleNode(head);
        ListNode* firstHalf=head;
        
        ListNode* secondHalf=middleNode->next;
        middleNode->next=NULL;

        secondHalf=reverse(secondHalf);
        ListNode* nextNodeInFirstHalf,nextNodeInSecondHalf;

        while(firstHalf && secondHalf){
            ListNode* firstFront=firstHalf->next;
            ListNode* secondFront=secondHalf->next;

            firstHalf->next=secondHalf;
            secondHalf->next=firstFront;

            firstHalf=firstFront;
            secondHalf=secondFront;
        }
        
    }
};
