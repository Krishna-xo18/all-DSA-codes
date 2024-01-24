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

    int count(int n){
        int x=0;
        while(n!=0){
          x+=(n&1);
          n=n>>1;
        }
        return x;
    }
    void solve(TreeNode*root,int num,int &ans){
        if(root->left==NULL && root->right==NULL){
            num = num^(1<<root->val);
            if(count(num)<=1){
                ans++;
            }
            return ;
        }
        num = num^(1<<root->val);
        if(root->left){
            solve(root->left,num,ans);
        }
        if(root->right){
            solve(root->right,num,ans);
        }
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        solve(root,0,ans);
        return ans;
    }
};