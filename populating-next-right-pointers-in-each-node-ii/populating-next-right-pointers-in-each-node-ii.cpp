/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>>level;
        if(root==NULL){
            return root;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<Node*>alpha;
             for(int i=0;i<size;i++){
                 Node*temp=q.front();
                 q.pop();
                 alpha.push_back(temp);
                 if(temp->left){
                     q.push(temp->left);
                 }
                 if(temp->right){
                     q.push(temp->right);
                 }
             }
             alpha.push_back(NULL);
             level.push_back(alpha);
        }
        for(int i=0;i<level.size();i++){
            for(int j=0;j<level[i].size()-1;j++){
                level[i][j]->next=level[i][j+1];
            }
        }
        return root;
    }

};