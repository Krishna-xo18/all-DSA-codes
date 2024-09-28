class Solution {
public:
    #define ll long long 
    ll int dp[20][2];
    ll int solve(int idx,int tight ,string num,string suffix,int limit){
        if(num.size() < suffix.size()){
            return 0;
        }
        if(idx==(num.size()-suffix.size())){
            if(!tight){
                return 1;
            }
            return (num.substr(num.size()-suffix.size()) >= suffix) ? 1:0;
        }
        if(dp[idx][tight]!=-1)return dp[idx][tight];

         ll ans=0;
        ll int maxi=  (tight)? min(num[idx]-'0',limit) : limit;
         for(int i=0;i<=maxi;i++){
            ans+=solve(idx+1,(tight) ? ((i<num[idx]-'0') ? 0 : 1 ) : 0 ,num,suffix,limit);
         }
         return dp[idx][tight]=ans;

    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
       start--;
       string num1=to_string(start);
       memset(dp,-1,sizeof(dp));
       ll int ans1=solve(0,1,num1,s,limit);
       memset(dp,-1,sizeof(dp));
       string num2=to_string(finish);
       ll int ans2=solve(0,1,num2,s,limit);
       
       return ans2-ans1;
       
    }
};