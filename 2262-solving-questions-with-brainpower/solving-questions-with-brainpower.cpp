class Solution {
public:
     long long solve(int idx,vector<vector<int>>& questions,vector<long long int>&dp){
         if(idx>=questions.size()){
             return 0;
         }
         if(dp[idx]!=-1){
             return dp[idx];
         }
         long long int take=0;
         long long int nottake=solve(idx+1,questions,dp);
         {
             take=questions[idx][0]+solve(idx+questions[idx][1]+1,questions,dp);
         }
         return dp[idx]=max(take,nottake);
     }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long int>dp(questions.size()+1,-1);
         return solve(0,questions,dp);
    } 
};