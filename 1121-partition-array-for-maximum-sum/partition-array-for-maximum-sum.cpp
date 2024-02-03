class Solution {
public:
    int dp[502][502];
    int solve(int idx,int last_idx,int k,int maxi,vector<int>&arr){
        if(idx==arr.size()){
            return (arr.size()-1-last_idx)*maxi;
        }
       if(dp[idx][last_idx+1]!=-1){
           return dp[idx][last_idx+1];
       }

        maxi=max(maxi,arr[idx]);
        int notpartion=0;
        int partion=(idx-last_idx)*maxi+solve(idx+1,idx,k,0,arr);
        
        if(idx-last_idx<k){
           notpartion=solve(idx+1,last_idx,k,maxi,arr);
        }

        return dp[idx][last_idx+1]=max(partion,notpartion);
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,k,0,arr);
    }
};