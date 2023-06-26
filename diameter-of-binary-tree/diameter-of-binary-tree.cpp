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
  int height(TreeNode*root){
      if(root==NULL){
          return 0;

      }
      int leftheight=height(root->left);
      int rightheight=height(root->right);
      return 1+max(leftheight,rightheight);
  }
    int diameter=0;
    void smalldiameter(TreeNode*node){
       if(node==NULL){
           return;
       }
        int x=height(node->left);
        int y=height(node->right);

        diameter=max(diameter,x+y);
        smalldiameter(node->left);
        smalldiameter(node->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        smalldiameter(root);

        return diameter;
    }
};