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
    struct Compare{
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> minHeap;

        for(auto list : lists){
            ListNode * temp=list;
            while(temp){
                ListNode* front=temp->next;
                temp->next=NULL;
                minHeap.push(temp);
                temp=front;
            }
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(!minHeap.empty()){
            temp->next=minHeap.top();
            minHeap.pop();
            temp=temp->next;
        }

        return dummy->next;
    }
};
