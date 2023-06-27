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
    int maxLevelSum(TreeNode* root) {
      //  priority_queue<pair<int,int>>pq;
        queue<TreeNode*>q;
        if(root==NULL){
            return 0;
        }
        q.push(root);
        int finalsum=INT_MIN;
        int sum=0;
        int count=0;
        int ans=0;
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
              if(finalsum<sum ){
                  finalsum=sum;
                  ans=count;
              }


        }
        return ans;
    }
};