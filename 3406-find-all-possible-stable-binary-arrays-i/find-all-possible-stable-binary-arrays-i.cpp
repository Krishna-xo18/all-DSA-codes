class Solution {
public:
   
    #define ll long long 
   int dp[201][201][201][3];
    ll int mod=1e9+7;
   ll int solve(int ones,int zeros,int prev,int consecutive,int limit){
        if(consecutive>limit || ones<0 || zeros<0 ){
            return 0;
        }
        if(ones==0 && zeros==0){
            return 1;
        }
        
       if(dp[zeros][ones][consecutive][prev]!=-1)return dp[zeros][ones][consecutive][prev];
            ll int ans=0;
          if(ones) ans+=((solve(ones-1,zeros,1,(prev==1) ? consecutive+1:1,limit)))%mod;
            if(zeros) ans+=((solve(ones,zeros-1,0,(prev==0) ? consecutive+1:1,limit)))%mod;
            
      return dp[zeros][ones][consecutive][prev]=(ans)%mod;
       
        
    }
    int numberOfStableArrays(int zero, int one, int limit) {
         for(int  i = 0 ; i <= zero ; i++)
            for(int j = 0 ; j <= one ; j++)
                for(int  k = 0 ; k <= limit; k++)
                    dp[i][j][k][0] = dp[i][j][k][1] = dp[i][j][k][2] = -1;
         
        return solve(one,zero,0,0,limit);
    }
};