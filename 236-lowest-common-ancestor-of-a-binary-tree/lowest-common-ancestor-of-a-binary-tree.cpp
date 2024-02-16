/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root,int x){
        if(root==NULL){
            return false;
        }
        if(root->val==x){
            return true;
        }
        return check(root->left,x) || check(root->right,x);
        
    }
    int height(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int left=1+height(root->left);
        int right=1+height(root->right);
        return max(left,right);
    }
    void solve(TreeNode* root,int val1,int val2,int &ans,int min_height){
        if(root==NULL){
            return ;
        }
        if(check(root,val1) && check(root,val2)){
            int h=height(root);
            if(h<min_height){
                ans=root->val;
                min_height=h;
            }
        }
        solve(root->left,val1,val2,ans,min_height);
        solve(root->right,val1,val2,ans,min_height);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val1=p->val;
        int val2=q->val;
        int ans=-1;
        solve(root,val1,val2,ans,INT_MAX);
        TreeNode* temp = new TreeNode(ans);
        return temp;
    }
};