class DisjointSet {
   
public: 
     vector<int> rank, parent, size; 
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
  
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nrow=i+dx[k];
                        int ncol=j+dy[k];
                        if(nrow>-1 && nrow<n && ncol>-1 && ncol<n && grid[nrow][ncol]){
                            ds.unionBySize(i*n+j,nrow*n+ncol);
                        }
                    }
                }
            }
        }
        int ans=ds.size[ds.findUPar(0)];
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>s;
                    for(int k=0;k<4;k++){
                        int nrow=i+dx[k];
                        int ncol=j+dy[k];
                        if(nrow>-1 && nrow<n && ncol>-1 && ncol<n && grid[nrow][ncol]){
                            s.insert(ds.findUPar(nrow*n+ncol));
                        }
                    }
                    int temp=1;
                    for(auto it:s){
                        temp+=ds.size[it];
                    }
                    ans=max(temp,ans);
                }
            }
        }
        return ans;
    }
};