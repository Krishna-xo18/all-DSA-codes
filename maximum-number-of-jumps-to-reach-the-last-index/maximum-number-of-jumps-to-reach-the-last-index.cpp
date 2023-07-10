class Solution {
public:
    int solve(vector<int>&nums,int index,int target,vector<int>&dp){
        if(index==0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans=INT_MIN;
        for(int i=0;i<index;i++){
            if(abs(nums[index]-nums[i])<=target){
                int alpha=solve(nums,i,target,dp);
               ans =max(ans,1+alpha);
            }
        }
     
         return dp[index]=ans;
        
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size()+1,-1);
        int x= solve(nums,nums.size()-1,target,dp);
       if(x>0){
           return x;
       }
       return -1;
    }
};