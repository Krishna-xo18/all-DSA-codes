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
   bool flag=false;
   vector<int>lastinsert;
    void solve(TreeNode*root,int sum,int targetSum){
      if(root==NULL){
          return;
      }
      if(root->left==NULL && root->right==NULL){
          sum+=root->val;
          if(sum==targetSum){
           flag=true;
          }
          sum=sum-root->val;
          
          return;
      }
      sum+=root->val;
      lastinsert.push_back(root->val);
      solve(root->left,sum,targetSum);
      solve(root->right,sum,targetSum);
      sum=sum-root->val;
      
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root,0,targetSum);
        return flag;
    }
};