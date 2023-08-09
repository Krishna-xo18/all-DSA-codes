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
    int length(ListNode*head){
        int count=0;
        while(head!=NULL){
            head=head->next;
            count++;

        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        int len=length(temp);
        if(len-n==0){
            return head->next;
        }
        for(int i=1;i<len-n;i++){
            temp=temp->next;
        }
        if(temp->next==NULL){
            return NULL;
        }
        if(temp->next->next==NULL){
            temp->next=NULL;
            return head;
        }
        temp->next=temp->next->next;
        return head;
    }
};