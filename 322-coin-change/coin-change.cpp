class Solution {
public:
    int solve(int idx,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(idx<0){
            if(target ==0){
                return 0;
            }
            return 1e9;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int nottake=0+solve(idx-1,target,coins,dp);
        int take=1e9;
        if(target>=coins[idx]){
            take=1+solve(idx,target-coins[idx],coins,dp);
        }
        return dp[idx][target]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int x=solve(coins.size()-1,amount,coins,dp);
      if(x==1e9){
          return -1;
      }
      return x;
        

    }
};