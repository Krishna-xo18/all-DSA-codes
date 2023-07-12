class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp){
        //reaching start
       if(i==0 && j==0){
           return 1;
       }
       //excedding the boundaries
       if(i<0 || j<0){
           return 0;
       }
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
       int up=solve(i-1,j,dp);
       int left=solve(i,j-1,dp);
       return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        //move down or right so if we go from bottom it will be up or left
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};