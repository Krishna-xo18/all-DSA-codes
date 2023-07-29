class Solution {
public:
     int solve(int idx,int buy,vector<int>&prices,vector<vector<int>>&dp){
      if(idx==prices.size()){
          return 0;
      }
      if(dp[idx][buy]!=-1){
          return dp[idx][buy];
      }
      int profit=0;
      if(buy){
          int take=-prices[idx]+solve(idx+1,0,prices,dp);
          int nottake=0+solve(idx+1,1,prices,dp);
          profit=max(take,nottake);
      }
      else{
          int take=prices[idx]+solve(idx+1,1,prices,dp);
          int nottake=0+solve(idx+1,0,prices,dp);
          profit=max(take,nottake);
      }
     return dp[idx][buy]=profit;

      
     }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};