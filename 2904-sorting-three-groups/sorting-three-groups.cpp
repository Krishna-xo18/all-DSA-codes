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
       if(prev==0 || nums[idx-1]>=nums[prev-1]){
           take=1+solve(idx+1,idx,nums,dp);
       }
       return dp[idx][prev]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
     vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
      return solve(1,0,nums,dp);

    }
    int minimumOperations(vector<int>& nums) {
        return nums.size()-lengthOfLIS(nums);
    }
};