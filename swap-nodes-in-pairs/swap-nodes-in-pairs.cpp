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
    ListNode* swapPairs(ListNode* head) {
        ListNode*temp1=head;
        if(temp1==NULL || temp1->next==NULL){
            return temp1;
        }
       ListNode*temp2=temp1->next;
        while(1){
           int val1=temp1->val;
           int val2=temp2->val;
           temp1->val=val2;
           temp2->val=val1;
           temp1=temp2->next;
           if(temp1==NULL || temp1->next==NULL){
               break;
           }
           temp2=temp1->next;
        }
        return head;
    }
};