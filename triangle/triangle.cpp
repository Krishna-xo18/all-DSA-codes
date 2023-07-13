class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        int ans=INT_MAX;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j>=0 && j<=triangle[i+1].size()-1){
            int path1=triangle[i][j]+solve(i+1,j,triangle,dp);
            ans=min(path1,ans);
        }
        if(j>=0 && j<triangle[i+1].size()-1){
            int path2=triangle[i][j]+solve(i+1,j+1,triangle,dp);
            ans=min(path2,ans);
        }
       
        return dp[i][j]=ans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int x=triangle.size();
        int y=triangle[triangle.size()-1].size();
        vector<vector<int>>dp(x,vector<int>(y,-1));
      return solve(0,0,triangle,dp);
    }
};