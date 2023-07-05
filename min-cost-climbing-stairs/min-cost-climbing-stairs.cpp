class Solution {
public:
    int solve(vector<int>&cost,int idx,vector<int>&dp){
        if(idx==0 ){
            return cost[0];
        }
        if(idx==1){
            return cost[1];
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }
        int path1=solve(cost,idx-1,dp)+cost[idx];
        int path2=solve(cost,idx-2,dp)+cost[idx];

        return dp[idx]=min(path1,path2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(solve(cost,cost.size()-1,dp),solve(cost,cost.size()-2,dp));
    }
};