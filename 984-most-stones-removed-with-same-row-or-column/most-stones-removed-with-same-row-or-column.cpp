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
    int removeStones(vector<vector<int>>& stones) {
        map<int,vector<int>>mp_x;
        map<int,vector<int>>mp_y;
        int n=stones.size();
         DisjointSet ds(n);
        for(int i=0;i<stones.size();i++){
            mp_x[stones[i][0]].push_back(i);
            mp_y[stones[i][1]].push_back(i);
        }
        for(auto x:mp_x){
            auto vec=x.second;
            int y=vec[0];
            for(int i=1;i<vec.size();i++){
                ds.unionBySize(vec[i],y);
            }
        }
         for(auto x:mp_y){
            auto vec=x.second;
            int y=vec[0];
            for(int i=1;i<vec.size();i++){
                ds.unionBySize(vec[i],y);
            }
        }
        set<int>s;
        for(int i=0;i<stones.size();i++){
          s.insert(ds.findUPar(i));
        }
        int ans=0;
       for(auto it:s){
          ans+=(ds.size[it]-1);
       }
       return ans;

    }
};