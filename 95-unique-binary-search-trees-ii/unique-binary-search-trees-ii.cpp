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
    vector<TreeNode*> generateTrees1(int start,int end) {
        vector<TreeNode*>v;
        if(start>end){
              v.push_back(NULL);
              return v;
        }
        //vector<TreeNode*>ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left=generateTrees1(start,i-1);
            vector<TreeNode*>right=generateTrees1(i+1,end);
            for(auto l:left){
                for(auto r:right){
                    TreeNode*root=new TreeNode();
                    root->val=i;
                    root->left=l;
                    root->right=r;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode*>V;
        if(n==0) return V;
        
        return generateTrees1(1,n);
    }
};