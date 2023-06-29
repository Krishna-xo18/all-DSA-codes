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
   
    int height(TreeNode*node){
        if(node==NULL){
            return 0;
        }
        int left=height(node->left);
        int right=height(node->right);
        return 1+max(left,right);
    }
   
    vector<vector<string>> printTree(TreeNode* root) {
        TreeNode*temp=root;
        int x=height(temp)-1;
        int m=x+1;
        int n=pow(2,x+1)-1;
        vector<vector<string>>ans(m,vector<string>(n,""""));
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,(n-1)/2}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode*Node=p.first;
            int i=p.second.first;
            int j=p.second.second;
            ans[i][j]=to_string(Node->val);
            if(Node->left){
                q.push({Node->left,{i+1,j-pow(2,x-i-1)}});
            }
            if(Node->right){
                q.push({Node->right,{i+1,j+pow(2,x-i-1)}});
            }
        }
        return ans;
    }
};