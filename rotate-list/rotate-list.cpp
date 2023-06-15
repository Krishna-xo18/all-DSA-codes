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

    int length(ListNode*temp){
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
      return len;
    }
   
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ){
            return NULL;
        }
        
          ListNode*temp=head;
          int len=length(temp);
          if(len==1){
              return temp;
          }
          
        long long int updatedk=k%len;
        if(updatedk==0){
            return head;
        }
       int pointer=1;
       ListNode*headofforward=NULL;
       ListNode*headofbackward=NULL;
       ListNode*temp1=new ListNode();
       temp1->val=temp->val;
       temp1->next=NULL;
       headofforward=temp1;
       ListNode*temp2=new ListNode();
        while(temp!=NULL){
             if(pointer!=1 &&  pointer<=len-updatedk){
                ListNode*add=new ListNode(temp->val);             
                temp1->next=add;
                temp1=add;
            }
           else  if(pointer==len-updatedk+1){
                temp2->val=temp->val;
                temp2->next=NULL;
               
                headofbackward=temp2;
            }
            else if( pointer>len-updatedk+1 && pointer<=len){
              ListNode*add=new ListNode(temp->val);
                temp2->next=add;
                temp2=add;
            }

            pointer++;
            temp=temp->next;
        }
         ListNode*finalans=headofbackward;
         while(headofbackward!=NULL && headofbackward->next!=NULL){
             headofbackward=headofbackward->next;
         }
         headofbackward->next=headofforward;
         return finalans;
    }
};