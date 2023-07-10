class Solution {
public:
       int solve(int idx,vector<int>&nums,vector<int>&dp){
	    if(idx==0){
	        return nums[0];
	    }
	    if(idx<0){
	        return 0;
	    }
	    if(dp[idx]!=-1){
	        return dp[idx];
	    }
	    int pick=nums[idx]+solve(idx-2,nums,dp);
	    int notpick=0+solve(idx-1,nums,dp);
	   return  dp[idx]=max(pick,notpick);
   }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums.size()-1,nums,dp);
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int n=10001;
        vector<int>sum(n,0);
        for(auto element:mp){
            sum[element.first]=element.second*element.first;
        }
        return rob(sum);

    }
};