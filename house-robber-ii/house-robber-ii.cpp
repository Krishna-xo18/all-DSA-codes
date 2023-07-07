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
    int rob1(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums.size()-1,nums,dp);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>temp1;
        vector<int>temp2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i!=0){
                //to not include the first element
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                //to not include the last element
                temp2.push_back(nums[i]);
            }
        }
        return max(rob1(temp1),rob1(temp2));
    }
};