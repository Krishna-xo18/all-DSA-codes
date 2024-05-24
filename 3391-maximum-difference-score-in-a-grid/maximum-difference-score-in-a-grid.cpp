class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>> &dp){
        if(i==(n-1) && j==(m-1)){
            return dp[i][j]=0;
        }
        int ans=-1e6;
        if(dp[i][j]!=-1e6){
            return dp[i][j];
        }
        if((i+1)<n){
            ans=max(ans,grid[i+1][j]-grid[i][j]+helper(grid,i+1,j,n,m,dp));
            ans=max(ans,grid[i+1][j]-grid[i][j]+helper(grid,n-1,m-1,n,m,dp));
        }
        if((j+1)<m){
            ans=max(ans,grid[i][j+1]-grid[i][j]+helper(grid,i,j+1,n,m,dp));
            ans=max(ans,grid[i][j+1]-grid[i][j]+helper(grid,n-1,m-1,n,m,dp));
        }
        return dp[i][j]=ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1e6));
        helper(grid,0,0,n,m,dp);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==(n-1) && j==(m-1)){
                    continue;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};