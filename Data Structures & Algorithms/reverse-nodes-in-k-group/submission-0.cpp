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
    pair<ListNode*,ListNode*> reverseTheSubLists(ListNode* head){
        ListNode* temp=head;
        ListNode* prevNode=NULL;

        while(temp){
            ListNode* frontNode=temp->next;

            temp->next=prevNode;
            prevNode=temp;
            temp=frontNode;
        }

        return {prevNode,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        if(!head || !head->next) return head;

        ListNode* temp=head;
        int count=0;
        ListNode* firstNode=head;
        ListNode* prevNode=NULL;
        ListNode* newHead=head;

        while(temp){
           count++;
           if(count==1){
              firstNode=temp;
           }
           if(count==k){
               ListNode* nextNode=temp->next;
               temp->next=NULL;
               auto revHead=reverseTheSubLists(firstNode);

                if(prevNode) {
                  prevNode->next=revHead.first;
                }
                else{
                 newHead=revHead.first;
                }
                revHead.second->next=nextNode;

               count=0;
               temp=nextNode;
               prevNode=revHead.second;
               continue;
           }
           temp=temp->next;
        }

        return newHead;
    }
};
