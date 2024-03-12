class Solution {
public:
    int dp[51][51][51][51];
    int solve(int r1,int c1,int r2,int c2,int n, vector<vector<int>>&grid){
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return -1e9;
        }

     if(r1==n-1 && c2==n-1 && r2==n-1 && c1==n-1){
       {
            return grid[r1][c1];
        }
        
     }
     if(dp[r1][c1][r2][c2]!=-1){
        return dp[r1][c1][r2][c2];
     }
      int ans=0;
      if(r1==r2 && c1==c2){
        if(grid[r1][c1]==1){
            ans++;
        }
      }
      else{
            if(grid[r1][c1] == 1){
                ans++;
            }
            if(grid[r2][c2] == 1){
                ans++;
            }
        }
        int path1=solve(r1+1,c1,r2+1,c2,n,grid);
        int path2=solve(r1+1,c1,r2,c2+1,n,grid);
        int path3=solve(r1,c1+1,r2+1,c2,n,grid);
        int path4=solve(r1,c1+1,r2,c2+1,n,grid);
        ans+=max(max(path1,path2),max(path3,path4));
        return dp[r1][c1][r2][c2]=ans;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,0,n,grid);
    
        return max(0,ans);
    }
};