class Solution {
public:
    int solve(int idx,int n,vector<int>&ans,vector<vector<int>>&dp){
           if(idx==0){
            if(n%ans[idx]==0){
                return n/ans[idx];
            }
            return 1e9;
           }  
           if(dp[idx][n]!=-1){
               return dp[idx][n];
           }
           if(n<0){
               return 1e9;
           }
           int take=1e9;
           int nottake=solve(idx-1,n,ans,dp);
           if(n>=ans[idx]){
               take=1+solve(idx,n-ans[idx],ans,dp);
           }
           return dp[idx][n]=min(take,nottake);
    }
    int numSquares(int n) {
       
        vector<int>ans;
         int i=1;
        while(i*i<=n){
            ans.push_back(i*i);
            i++;
        }
         vector<vector<int>>dp(ans.size()+1,vector<int>(n+1,-1));
       return solve(ans.size()-1,n,ans,dp);
    }
};