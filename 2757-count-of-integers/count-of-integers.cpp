class Solution {
public:
   #define ll long long
     ll int mod=1e9+7;
     int dp[25][2][1000];
    int solve(int pos,int tight,int sum,int min_sum,int max_sum,string s){
        if(pos==s.size()){
           if(sum>=min_sum && sum<=max_sum){
            return 1;
           }
           return 0;
        }
        if(dp[pos][tight][sum]!=-1){
            return dp[pos][tight][sum];
        }
       ll int res=0;
        if(tight==1){
            for(int i=0;i<=s[pos]-'0';i++){
                if(i==s[pos]-'0') res+=solve(pos+1,1,sum+i,min_sum,max_sum,s);
                else res+=solve(pos+1,0,sum+i,min_sum,max_sum,s);
            }
        }
        else if(tight==0){
            for(int i=0;i<=9;i++){
                res+=(ll)solve(pos+1,0,sum+i,min_sum,max_sum,s);
            }
        }
        return dp[pos][tight][sum]=res%mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        //pos=23,tight 2,sum 250
      
        memset(dp,-1,sizeof(dp));
        ll ans1=(solve(0,1,0,min_sum,max_sum,num1));
        memset(dp,-1,sizeof(dp));
        ll ans2=(solve(0,1,0,min_sum,max_sum,num2));
        int val=0;
        for(int i=0;i<num1.size();i++){
            val+=num1[i]-'0';
        }
        
        return (ans2-ans1+((val>=min_sum && val<=max_sum)?1:0)+mod)%mod;
    }
};