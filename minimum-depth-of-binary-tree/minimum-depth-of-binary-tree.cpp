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
   
    int minDepth(TreeNode* root) {
         queue<TreeNode*>q;
         int mini=INT_MAX;
        int count=0;
        if(root==NULL){
            return 0;
        }
        q.push(root);
        
        while(!q.empty()){
            count++;
            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                if(temp->left==NULL && temp->right==NULL){
                       mini=min(mini,count);
                }
                 q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return mini;
    }
};