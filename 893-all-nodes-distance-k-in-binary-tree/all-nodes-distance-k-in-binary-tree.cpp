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
    void traversal(TreeNode* root,map<int,vector<int>>&mp){
        if(root==NULL){
            return ;
        }
        if(root->right){
            mp[root->right->val].push_back(root->val);
             mp[root->val].push_back(root->right->val);
             traversal(root->right,mp);
        }
         if(root->left){
            mp[root->left->val].push_back(root->val);
             mp[root->val].push_back(root->left->val);
             traversal(root->left,mp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int,vector<int>>mp;
        
        traversal(root,mp);
   
        vector<int>ans;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{target->val,-1}});
        while(!q.empty()){
            auto node=q.front();
           int child=node.second.first;
           int parent=node.second.second;
           int dis=node.first;
           q.pop();
         
           if(dis==k){
               ans.push_back(child);
           }
           auto vec=mp[child];
           for(int i=0;i<vec.size();i++){
               if(dis<k && vec[i]!=parent) q.push({dis+1,{vec[i],child}});
               
           }
        }
        return ans;
    }
};