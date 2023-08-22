class Solution {
public:
    int dp[1001][1001];
    int solve(int idx1,int idx2,int &maxlen,vector<int>&nums1,vector<int>&nums2){
        if(idx1==0 || idx2==0){
            return 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int count=0;
        if(nums1[idx1-1]==nums2[idx2-1]){
            count=1+solve(idx1-1,idx2-1,maxlen,nums1,nums2);
        }
        maxlen=max(count,maxlen);
        solve(idx1-1,idx2,maxlen,nums1,nums2);
        solve(idx1,idx2-1,maxlen,nums1,nums2);
        return dp[idx1][idx2]=count;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int maxlen=0;
    
         
         for(int idx1=1;idx1<=nums1.size();idx1++){
             for(int idx2=1;idx2<=nums2.size();idx2++){
                if(nums1[idx1-1]==nums2[idx2-1]){
                    dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                    maxlen=max(maxlen,dp[idx1][idx2]);
                }
                else{
                    dp[idx1][idx2]=0;
                }
             }
         }
         return maxlen;
    }
};