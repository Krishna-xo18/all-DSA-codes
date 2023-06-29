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
    //mapping every value to their index in inorder traversal
      map<int,int>m;
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        //calling the function with values
        TreeNode* root = build(pre,0,pre.size()-1,in,0,in.size()-1);
        return root;
    }
    TreeNode* build(vector<int>&pre,int preStart,int preEnd,vector<int>&in, int inStart,int inEnd){
         //base case for completion
        if(preStart>preEnd || inStart>inEnd)return NULL;
        //creating a new node
        TreeNode* root = new  TreeNode(pre[preStart]);
        //getting the index using map
        int index = m[pre[preStart]];
        //getting the no of elements on left
        int len = index - inStart;
        //using the pointers prestart,preend,instart,inend to construct
        root->left = build(pre,preStart+1,preStart+len,in,inStart,index-1);
        root->right = build(pre,preStart+len+1,preEnd,in,index+1,inEnd);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);
    }
};