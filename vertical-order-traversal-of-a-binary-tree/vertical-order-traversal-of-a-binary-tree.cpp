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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //data structure to store the nodes with their indices(x,y)
        map<int,map<int,multiset<int>>>nodes;
        //data structure for iteration and assigning the values
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode*temp=p.first;
            int vertical=p.second.first;
            int level=p.second.second;
            //inserting values in multiset
            nodes[vertical][level].insert(temp->val);
            if(temp->left){
                q.push({temp->left,{vertical-1,level+1}});
            }
            if(temp->right){
                q.push({temp->right,{vertical+1,level+1}});
            }
        }
        vector<vector<int>>ans;

        for(auto p:nodes){
            vector<int>col;
            //p.first===int  p.second=map<int,multiset>
            for(auto q:p.second){
                //copying the particular multiset to vector
                 col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;

    }
};