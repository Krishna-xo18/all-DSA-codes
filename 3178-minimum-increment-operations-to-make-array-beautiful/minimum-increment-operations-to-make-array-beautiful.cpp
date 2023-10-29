class Solution {
public:
    #define ll long long
    ll int dp[100001][4];
 
    ll int solve(int idx,int lastupdate,vector<int>&nums,int k)
    {
        if(idx>=nums.size()){
            return 0;
        }   
        if(dp[idx][lastupdate]!=-1){
            
            return dp[idx][lastupdate];
        }
        ll int skip=1e14;
        if(lastupdate<3  ||  nums[idx]>=k){
            if(nums[idx]>=k){
                skip=(solve(idx+1,1,nums,k));
            }
            else{
                skip=(solve(idx+1,lastupdate+1,nums,k));
            }
            
        }
        ll int notskip=(max(0,k-nums[idx])+solve(idx+1,1,nums,k));
        
        return dp[idx][lastupdate]=min(skip,notskip);
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,nums,k);
    }
};