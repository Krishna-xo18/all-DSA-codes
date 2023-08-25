class Solution {
public:
    long long int dp[31][1001];
    long long M=1e9+7;
    int solve(int dice,int target,vector<int>&ans,int n){
        if(target==0 && dice>n){
            return 1;
        }
        if(dice>n || target<0){
            return 0;
        }
        if(dp[dice][target]!=-1){
            return (dp[dice][target])%M;
        }
        
        long long int ans1=0;
        for(int i=0;i<ans.size();i++){
           ans1=((ans1)%M+(solve(dice+1,target-ans[i],ans,n))%M)%M;
        }
        return dp[dice][target]=(ans1)%M;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<int>ans;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=k;i++){
            ans.push_back(i);
        }
        return solve(1,target,ans,n);
    }
};