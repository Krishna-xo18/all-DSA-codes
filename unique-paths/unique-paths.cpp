class Solution {
public:
    int solve(int m,int n,vector<vector<int>>&dp){

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }
    }
       return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        //move down or right so if we go from bottom it will be up or left
        vector<vector<int>>dp(m+10,vector<int>(n+10,1));
        return solve(m,n,dp);
    }
};