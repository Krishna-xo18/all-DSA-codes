class Solution {
public:
     int solve(int index,vector<int>&nums,unordered_map<int,int>&mp,vector<int>&dp){
        if(index==nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int pick=nums[index]*mp[nums[index]]+solve(upper_bound(nums.begin(),nums.end(),nums[index]+1)-nums.begin(),nums,mp,dp);
        int notpick=0+solve(index+1,nums,mp,dp);
        return dp[index]=max(pick,notpick);
     }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,mp,dp);
    }
};