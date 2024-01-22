class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&color){
        vis[node]=1;
        int colors=color[node];
        for(auto adjnode: adj[node]){
            if(!vis[adjnode]){
                color[adjnode]=!colors;
                if(!dfs(adjnode,adj,vis,color)){
                    return false;
                }
            }
            else if(color[adjnode]==colors){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>vis(n+1,0);
        vector<int>color(n+1,0);
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                if(!dfs(i,adj,vis,color)){
                    return false;
                }
            }
        }
        return true;
    }
};