class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,int m,int n,int &area){
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
         area=area+1;
         grid[i][j]=0;
        for(int k=0;k<4;k++){
           int nrow=i+dx[k];
           int ncol=j+dy[k];
           if(nrow>-1 && nrow<m && ncol>-1 && ncol<n && grid[nrow][ncol]==1){
               grid[nrow][ncol]=0;
               dfs(nrow,ncol,grid,m,n,area);
           }
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=0;
                    dfs(i,j,grid,m,n,area);
                    max_area=max(max_area,area);
                }
            }
        }
        return max_area;
    }
};