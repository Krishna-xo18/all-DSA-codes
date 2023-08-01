class Solution {
public:
  int dp[1001][102][2];
   int solve(int idx,int buy,vector<int>&prices,int k){
      if(idx>=prices.size() || k<=0){
          return 0;
      }
      if(dp[idx][k][buy]!=-1){
          return dp[idx][k][buy];
      }
      int profit=0;
      if(buy){
          int take=-prices[idx]+solve(idx+1,0,prices,k);
          int nottake=0+solve(idx+1,1,prices,k);
          profit=max(take,nottake);
      }
      else{
          int take=prices[idx]+solve(idx+1,1,prices,k-1);
          int nottake=0+solve(idx+1,0,prices,k);
          profit=max(take,nottake);
      }
     
     return dp[idx][k][buy]=profit;
     }
    int maxProfit(int k, vector<int>& prices) {
    memset(dp,-1,sizeof(dp));
      return solve(0,1,prices,k);
    }
};