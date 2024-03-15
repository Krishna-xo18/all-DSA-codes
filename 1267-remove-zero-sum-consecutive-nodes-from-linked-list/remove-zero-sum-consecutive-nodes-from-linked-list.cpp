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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int>vec;
        ListNode* temp=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        map<int,vector<int>>mp;
        mp[0].push_back(-1);
        vector<int>check(vec.size(),0);
        int sum=0;
        for(int i=0;i<vec.size();i++){
           sum+=vec[i];
           if(mp.find(sum)!=mp.end()){
            vector<int>v=mp[sum];
            for(int j=0;j<v.size();j++){
                if(v[j]==-1 ||check[v[j]]==0){
                    for(int k=v[j]+1;k<=i;k++){
                        check[k]=1;
                    }
                }
            }
           }
           
           mp[sum].push_back(i);
        }
        ListNode* ans=new ListNode(0);
        ListNode* x=ans;
        for(int i=0;i<check.size();i++){
            if(check[i]==0){
                
              ListNode* ans1=new ListNode(vec[i]);
              ans->next=ans1;
              ans=ans->next;
            }
            
        }
        if(x==NULL)return NULL;
        return x->next;
        
         
    }
};