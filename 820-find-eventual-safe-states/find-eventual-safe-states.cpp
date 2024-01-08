class Solution {
public:
    bool dfs(int node,vector<int>&pathvis,vector<int>&vis,vector<int>&ans,vector<vector<int>>&graph){
        vis[node]=1;
        pathvis[node]=1;
          bool flag=true;
        for(int adjnode: graph[node]){
            
            if(!vis[adjnode]){
            if(!dfs(adjnode,pathvis,vis,ans,graph))
                 {
                    return false;
                 }
            }
            else if(pathvis[adjnode]){
                return false;
            }
        }
        pathvis[node]=0;
         ans.push_back(node);
         return true;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>pathvis(graph.size(),0);
        vector<int>vis(graph.size(),0);
        vector<int>ans;
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
               if(dfs(i,pathvis,vis,ans,graph)){

               }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};