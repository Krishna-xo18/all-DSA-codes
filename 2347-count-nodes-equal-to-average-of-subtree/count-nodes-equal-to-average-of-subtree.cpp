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
    int check_sum(TreeNode*root,int &count){
        if(root==NULL){
            return 0;
        }
        int sum=0;
        sum+=root->val;
        count++;
        if(root->left){
            sum+=check_sum(root->left,count);
        }
        if(root->right){
            sum+=check_sum(root->right,count);
        }
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count=0;
        int sum=check_sum(root,count);
        int ans=0;
        if(count>0){
            if(sum/count==root->val){
            ans++;
            }
        }
        if(root->left){
            ans+=averageOfSubtree(root->left);
        }
        if(root->right){
            ans+=averageOfSubtree(root->right);
        }
       return ans;
    }
};