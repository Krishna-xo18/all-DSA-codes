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
    ListNode* partition(ListNode* head, int x) {
        vector<int>less_x;
        vector<int>great_x;
        ListNode*temp=head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        while(temp!=NULL){
           if(temp->val<x){
               less_x.push_back(temp->val);
           }
           else{
               great_x.push_back(temp->val);
           }
           temp=temp->next;
        }
        for(auto x:great_x){
            less_x.push_back(x);
        }
        ListNode*temp1=new ListNode(less_x[0]);
        ListNode*ans=temp1;
        for(int i=1;i<less_x.size();i++){
            ListNode*temp2=new ListNode(less_x[i]);
            temp1->next=temp2;
            temp1=temp2;
        }
        return ans;
    }
};