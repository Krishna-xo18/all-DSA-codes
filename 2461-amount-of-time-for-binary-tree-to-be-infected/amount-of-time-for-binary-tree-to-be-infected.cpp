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
    void traversal(TreeNode* root,map<int,vector<int>>&mp){
        if(root==NULL){
            return ;
        }
        if(root->left!=NULL){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            traversal(root->left,mp);
        }
        if(root->right!=NULL){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            traversal(root->right,mp);
        }

    }
    int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>>mp;
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        traversal(root,mp);
        vector<int>vis(100001,0);
        queue<pair<int,int>>q;
        q.push({start,0});
        int max_time=0;
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            vis[node]=1;
            max_time=max(max_time,time);
            auto vec=mp[node];
            for(int i=0;i<vec.size();i++){
                if(!vis[vec[i]]){
                    vis[vec[i]]=1;
                  q.push({vec[i],time+1});
                }
               
            }
        }
        return max_time;
    }
};