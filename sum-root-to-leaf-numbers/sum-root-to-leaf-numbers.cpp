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
    vector<string>v;
    void solve(TreeNode*node,string &s){
        if(node==NULL){
            return ;
        }

       if(node->left==NULL && node->right==NULL){
           
            s+=to_string(node->val);
            v.push_back(s);
            s.pop_back();
          
            return;
       }
       s+=to_string(node->val);
       solve(node->left,s);
       solve(node->right,s);
       s.pop_back();
    
       return;
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        solve(root,s);
       int sum=0;
       for(int i=0;i<v.size();i++){
           sum+=stoi(v[i]);
       }
      
        return sum;
    }
};