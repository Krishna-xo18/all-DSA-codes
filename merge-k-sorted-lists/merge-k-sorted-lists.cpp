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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>values;
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        for(int i=0;i<lists.size();i++){
             ListNode*temp=lists[i];
            while(temp!=NULL){
                values.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(values.begin(),values.end());
        if(values.size()==0){
            return NULL;
        }
       
        ListNode*temp=new ListNode(values[0]);
       
        ListNode*headofans=temp;
        for(int i=1;i<values.size();i++){
            ListNode*add=new ListNode(values[i]);
            temp->next=add;
            temp=temp->next;
        }
        return headofans;
        
    }
};