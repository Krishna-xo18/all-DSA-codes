class Solution {
public:
   int dp[301][301];
    int solve(int start,int end,vector<int>&nums){
        
        if(start>end ){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int ans=INT_MIN;
        for(int i=start;i<=end;i++){
           
               ans=max(ans,nums[start-1]*nums[i]*nums[end+1]+solve(start,i-1,nums)+solve(i+1,end,nums));
           
        }
        return dp[start][end]=ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        vector<int>nums1;
        nums1.push_back(1);
        for(int i=0;i<nums.size();i++){
            nums1.push_back(nums[i]);
        }
        nums1.push_back(1);
        return solve(1,nums.size(),nums1);
    }
};