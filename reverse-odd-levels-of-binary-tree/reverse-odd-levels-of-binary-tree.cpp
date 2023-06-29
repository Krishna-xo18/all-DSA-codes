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
     vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                level.push_back(temp->val);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            reverse(level.begin(),level.end());
            ans.push_back(level);
        }
        return ans;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>>ans=levelOrder(root);
        if(root==NULL){
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        int j=-1;
        while(!q.empty()){
            int size=q.size();
            j++;
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
               if(j%2==1) temp->val=ans[j][i];
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        
        }
        return root;
    }
    
};