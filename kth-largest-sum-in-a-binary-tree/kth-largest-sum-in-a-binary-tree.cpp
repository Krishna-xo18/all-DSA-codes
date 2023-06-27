/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
         priority_queue<pair<long long int,long long int>>pq;
        queue<TreeNode*>q;
        if(root==NULL){
            return 0;
        }
        q.push(root);
       long long  int sum=0;
        long long int count=0;
        while(!q.empty()){
               int size=q.size();
               sum=0;
               count++;
               for(int i=0;i<size;i++){
                   TreeNode*temp=q.front();
                   q.pop();
                   sum+=temp->val;
                   if(temp->left){
                       q.push(temp->left);
                   }
                   if(temp->right){
                       q.push(temp->right);
                   }
               }
               pq.push({sum,count});


        }
        if(k>pq.size()){
            return -1;
        }
        k=k-1;
        while(k--){
            pq.pop();
        }
        return pq.top().first;
    }
};