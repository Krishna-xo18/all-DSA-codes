class Solution {
public:
   #define ll long long 
   ll int mod=1e9+7;
    ll int solve(int size,int code,int n, vector<vector<int>>&dp){
        if(size==n){
            return 1;
        }
         if(dp[size][code]!=-1){
             return dp[size][code];
         }


        ll int ans=0;
        if(code==0){
            ll int opt1=(solve(size+1,1,n,dp))%mod;
            ll int opt2=(solve(size+1,2,n,dp))%mod;
            ll int opt3=(solve(size+1,3,n,dp))%mod;
            ll int opt4=(solve(size+1,4,n,dp))%mod;
            ll int opt5=(solve(size+1,5,n,dp))%mod;
            ans+=((opt1+opt2+opt3+opt4+opt5))%mod;
        }
        else
        {
            
            if(code==1)
            {
               ans=(ans+(solve(size+1,2,n,dp)))%mod;
            }
            else if(code==2){
                ans=(ans+((solve(size+1,1,n,dp))%mod+(solve(size+1,3,n,dp))%mod))%mod;
            }
            else if(code==3){
                ans=(ans+((solve(size+1,1,n,dp))%mod+(solve(size+1,2,n,dp))%mod+(solve(size+1,4,n,dp))%mod+(solve(size+1,5,n,dp))%mod))%mod;
            }
            else if(code==4){
                ans=(ans+((solve(size+1,3,n,dp))%mod+(solve(size+1,5,n,dp))%mod))%mod;
            }
            else if(code==5){
                ans=(ans+(solve(size+1,1,n,dp)))%mod;
            }
            
        }
        return dp[size][code]=ans;

    }
    int countVowelPermutation(int n) {
        /*
        a=1;
        e=2;
        i=3;
        o=4;
        u=5;
        prev    next
        a       e
        e       a,i
        i       a,e,o,u
        o       i,u
        u       a
        */
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
        return solve(0,0,n,dp);

    }
};