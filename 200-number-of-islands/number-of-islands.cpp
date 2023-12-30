class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid, vector<vector<int>>&vis,int m ,int n){
         grid[i][j]='#';
         if(j>0 && j<=n-1) if(grid[i][j-1]=='1') dfs(i,j-1,grid,vis,m,n);
         if(i>0 && i<=m-1) if(grid[i-1][j]=='1') dfs(i-1,j,grid,vis,m,n);
         if(i<m-1 && i>=0) if(grid[i+1][j]=='1') dfs(i+1,j,grid,vis,m,n);
         if(j<n-1 && j>=0) if(grid[i][j+1]=='1') dfs(i,j+1,grid,vis,m,n);
    } 
    int numIslands(vector<vector<char>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
              for(int j=0;j<n;j++){
                  if(grid[i][j]=='1'){
                      if(!vis[i][j]){
                          ans++;
                          dfs(i,j,grid,vis,m,n);
                      }
                  }
              }
        }
        return ans;
    }
};