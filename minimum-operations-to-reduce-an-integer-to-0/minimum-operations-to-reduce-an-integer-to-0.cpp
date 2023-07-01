class Solution {
public:
    int solve(int n,vector<int>&dp){
       if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int i=1;
        while(1){
            if(pow(2,i)>=n){
                break;
            }
            i++;
        }
        int val1=abs(n-pow(2,i));
        int val2=abs(n-pow(2,i-1));
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=1+minOperations(min(val1,val2));
        return dp[n] ;
    }
    int minOperations(int n) {
       vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};