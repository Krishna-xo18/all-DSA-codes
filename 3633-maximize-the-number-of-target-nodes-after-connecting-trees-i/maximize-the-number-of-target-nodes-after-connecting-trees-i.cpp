class Solution {
public:
    int bfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis,int trans,int k){
        queue<pair<int,int>>q;
        if(trans==0)q.push({node,0});
        else q.push({node,1});
        int count=0;
        vis[node]=1;
     
        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            
            if(dis<=k)count++;
            for(auto &adjnode: adj[node]){
                if (!vis[adjnode]) {
                    vis[adjnode] = 1;
                    q.push({adjnode, dis + 1});
                }
            }
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int,int>mp_tree1;
        unordered_map<int,vector<int>>adj1;
        unordered_map<int,vector<int>>adj2;
        for(auto &x:edges1){
            adj1[x[0]].push_back(x[1]);
            adj1[x[1]].push_back(x[0]);
        }
        for(auto &x:edges2){
            adj2[x[0]].push_back(x[1]);
            adj2[x[1]].push_back(x[0]);
        }
        int n=adj1.size();
        int m=adj2.size();
        for(int i=0;i<adj1.size();i++){
            map<int,int>mp;
            vector<int>vis(n,0);
            int cnt=bfs(i,adj1,vis,0,k);
            mp_tree1[i]=cnt;
        }
        int maxi=0;
        for(int i=0;i<adj2.size();i++){
            map<int,int>mp;
            vector<int>vis(m,0);
            maxi=max(maxi,bfs(i,adj2,vis,1,k));
        }
        vector<int>ans(n,0);
        for(auto &x:mp_tree1){     
           ans[x.first]=x.second+maxi;
        }
        return ans;
    }
};