class Solution {
public:
   
    int solve(int idx,int prev,vector<int>&nums,vector<vector<int>>&dp){
        //shifting the index by 1
       if(idx==nums.size()+1){
           return 0;
       }
       if(dp[idx][prev]!=-1){
           return dp[idx][prev];
       }
       int take=0;
       int nottake=0;
       nottake=solve(idx+1,prev,nums,dp);
       if(prev==0 || nums[idx-1]>nums[prev-1]){
           take=1+solve(idx+1,idx,nums,dp);
       }
       return dp[idx][prev]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
     int ans=INT_MIN;
     for(int idx=n-1;idx>=0;idx--){
        for(int prev=idx-1;prev>=-1;prev--){
       int take=0;
       int nottake=0;
       nottake=dp[idx+1][prev+1];
       if(prev==-1 || nums[idx]>nums[prev]){
           take=1+dp[idx+1][idx+1];
       }
        dp[idx][prev+1]=max(take,nottake);
        }
     }
      return dp[0][0];

    }
};