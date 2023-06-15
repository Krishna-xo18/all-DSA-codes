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
 void Solve(ListNode* &head,ListNode* curr,ListNode* prev){

       if(curr==NULL){
            head=prev;
           return ;
       }
        ListNode*forward=curr->next;
         Solve(head,forward,curr);
            curr->next=prev;
        
      
   }
    
    ListNode* reverseList(ListNode* head) {
        ListNode*prev=NULL;
        ListNode*curr=head;
     
     
       Solve(head,curr,prev);
       return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*lenfinder=head;
        int len=0;
        if(head==NULL || head->next==NULL){
            return head;
        }
        while(lenfinder!=NULL){
           len++;
           lenfinder=lenfinder->next;
        }
        if(left==1 && right==len){
            return reverseList(head);
        }
        if(left==right){
            return head;
        }
        ListNode*temp1=head;
        ListNode*temp2=head;
        ListNode*temp3=head;
         if(left==1){
             temp1=NULL;
         }
        for(int i=0;i<left-2;i++){
          temp1=temp1->next;
        } 
     if(right==len){
         temp3=NULL;
     }
     else{
        for(int i=0;i<right;i++){
            temp3=temp3->next;

        }
     }
     if(temp1!=NULL){
        temp2=temp1->next;
     }
     else{
         temp2=head;
     }
        ListNode*prev=NULL;
        ListNode*curr=temp2;
        ListNode*forward=NULL;
       int count=1;
        while(count<=right-left+1){
            forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                count++;
          }
   if(temp1!=NULL)
   {
        temp1->next=prev;
   }
   
    temp2->next=temp3;
    if(temp1==NULL){
        return prev;
    }
        return head;

    }
};