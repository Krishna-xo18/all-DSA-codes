class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        
        for(auto adjnode: adj[node]){
            if(!vis[adjnode]){
                dfs(adjnode,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>vis(n,0);
        vector<int>adj[n+1];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
       
        int need=-1;
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
               
                dfs(i,adj,vis);
                need++; 
            }
        }
       
        int extra=0;
        DisjointSet ds(n);
        for(int i=0;i<connections.size();i++){
             if(ds.findUPar(connections[i][0])!=ds.findUPar(connections[i][1])){
                 ds.unionBySize(connections[i][0],connections[i][1]);
             }
             else{
                 extra++;
             }
        }
        if(need>extra){
            return -1;
        }
        return need;
        
    }
};