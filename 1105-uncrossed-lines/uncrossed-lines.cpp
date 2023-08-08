class Solution {
public:
    int dp[501][501];
    int solve(int idx1,int idx2,vector<int>&nums1,vector<int>&nums2){
        if(idx1==nums1.size() || idx2==nums2.size()){
            return 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int ans=0;
        if(nums1[idx1]==nums2[idx2]){
            ans=1+solve(idx1+1,idx2+1,nums1,nums2);
        }
        else{
            ans=max(solve(idx1+1,idx2,nums1,nums2),solve(idx1,idx2+1,nums1,nums2));
        }
        return dp[idx1][idx2]=ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1,nums2);
    }
};