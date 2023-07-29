class Solution {
public:
   int Solve(vector<int>& prices,int x) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
       int n=prices.size();
        dp[n][0]=dp[n][1]=0;
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
               int profit=0;
                if(buy){
                    int take=-prices[idx]+dp[idx+1][0];
                    int nottake=0+dp[idx+1][1];
                    profit=max(take,nottake);
                }
                        else{
                            int take=prices[idx]-x+dp[idx+1][1];
                            int nottake=dp[idx+1][0];
                            profit=max(take,nottake);
                        }
              dp[idx][buy]=profit;
            }
            
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return Solve(prices,fee);
    }
};