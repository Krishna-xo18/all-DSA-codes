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
    void func(TreeNode*root,int &mini,int &maxi){
        if(root==NULL){
            return ;
        }
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        if(root->left!=NULL){
            func(root->left,mini,maxi);
        }
        if(root->right!=NULL){
            func(root->right,mini,maxi);
        }
         
    }
    void solve(TreeNode*root,int &ans){
        if(root==NULL){
               return ;
        }
        int maxi=-1;
        int mini=1e9;
        if(root->left!=NULL){
           func(root->left,mini,maxi);
           ans=max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
           solve(root->left,ans);
        }
        maxi=-1;
        mini=1e9;
        if(root->right!=NULL){
            func(root->right,mini,maxi);
            ans=max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
           solve(root->right,ans);
        }
      
        

    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=-1;
        solve(root,ans);
        return ans;
    }
};