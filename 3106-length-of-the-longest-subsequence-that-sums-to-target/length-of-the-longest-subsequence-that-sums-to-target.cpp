class Solution {
public:
    int dp[1001][1001];
    int solve(int idx,int target,vector<int>&nums){
        if(target==0){
            return 0;
}
        if(target<0){
            return -1e9;
        }
        if(idx>=nums.size()){
            return -1e9;
}
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
         int take=1+solve(idx+1,target-nums[idx],nums);
        int nottake=solve(idx+1,target,nums);
       

        return dp[idx][target]=max(take,nottake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        if(solve(0,target,nums)<0){
            return -1;
        }
        return solve(0,target,nums);

    }
};