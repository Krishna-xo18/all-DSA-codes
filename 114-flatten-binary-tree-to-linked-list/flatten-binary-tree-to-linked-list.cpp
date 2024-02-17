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
      vector<int>pre;
    void preorder(TreeNode*root){
       if(root==NULL){
           return ;
       }
       pre.push_back(root->val);
       preorder(root->left);
       preorder(root->right);
    }
    void flatten(TreeNode* root) {
        preorder(root);
       
        TreeNode* temp=root;
        if(pre.size()==0){
             return;
        }
        root->val=pre[0];
        for(int i=1;i<pre.size();i++){
            TreeNode* root1= new TreeNode(pre[i]);
            root->left=NULL;
            root->right=root1;
            root=root->right;
        }
        root=temp;
    }
};