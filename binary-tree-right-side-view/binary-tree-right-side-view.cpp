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
              
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>alpha;
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                alpha.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);

                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(alpha[alpha.size()-1]);
        }
        return ans;
    }
};