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
    #define ll long long 
    ll int max(ll int a,ll int b){
        if(a>b) return a;
        return b;
    }
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<ll int,set<ll int>>mp;
        while(!q.empty()){
         auto node=q.front();
         auto temp=node.first;
         ll int level=node.second.first;
         ll int idx=node.second.second;
         q.pop();
         mp[level].insert(idx);
         if(temp->left){
             q.push({temp->left,{level+1,2*idx+1}});
         }
         if(temp->right){
             q.push({temp->right,{level+1,2*idx+2}});
         }
        }
        int ans=LLONG_MIN;
        for(auto x: mp){
            auto s=x.second;
            auto it1=s.begin();
            auto it2=s.end();
            it2--;
            ans=max(ans,abs(*it1-*it2));
        }
        return ans+1;
    }
};