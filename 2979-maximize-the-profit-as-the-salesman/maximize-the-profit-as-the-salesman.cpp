class Solution {
public:
    int solve(int idx,vector<vector<int>>&helper,vector<vector<int>>&offers,vector<int>&dp){
        if(idx>=helper.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int nottake=solve(idx+1,helper,offers,dp),take=0;
        for(int j=0;j<helper[idx].size();j++){
            int ind=helper[idx][j];
            int next=offers[ind][1]+1;
            int gold=offers[ind][2]+solve(next,helper,offers,dp);
            take=max(take,gold);
        }
        return dp[idx]=max(take,nottake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<int>>helper(n);
        for(int i=0;i<offers.size();i++){
            int idx=offers[i][0];
            helper[idx].push_back(i);
        }
        vector<int>dp(n,-1);
        return solve(0,helper,offers,dp);
        
    }
};