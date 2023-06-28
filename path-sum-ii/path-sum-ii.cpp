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
     vector<vector<int>>ans;
     void solve(TreeNode*root,int sum,int targetSum,vector<int>&temp){
      if(root==NULL){
          return ;
      }
      if(root->left==NULL && root->right==NULL){
          sum+=root->val;
          temp.push_back(root->val);
          if(sum==targetSum){
           ans.push_back(temp);
          }
          sum=sum-root->val;
          temp.pop_back();
      }
      sum+=root->val;
      temp.push_back(root->val);
      solve(root->left,sum,targetSum,temp);
      solve(root->right,sum,targetSum,temp);

      sum=sum-root->val;
      temp.pop_back();
      
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
     vector<int>temp;
     solve(root,0,targetSum,temp);
     return ans;
    }
};