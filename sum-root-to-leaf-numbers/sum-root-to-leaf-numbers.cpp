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
   int ans=0;
    void solve(TreeNode*root,string &s){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
           s+=to_string(root->val);
           ans+=stoi(s);
           s.pop_back();
           return;
        }
        s+=to_string(root->val);
        solve(root->left,s);
        solve(root->right,s);
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        solve(root,s);
        return ans;
    }
};