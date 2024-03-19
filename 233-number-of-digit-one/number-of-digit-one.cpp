class Solution {
public:
    int dp[10][2][10];
    int solve(int pos,int tight,int ones,string s){
        if(pos==s.size()){
            return ones;
        }
        if(dp[pos][tight][ones]!=-1){
            return dp[pos][tight][ones];
        }
        int res=0;
        if(tight==1){

            for(int i=0;i<=s[pos]-'0';i++){
                if(i==s[pos]-'0'){
                    if(i==1)
                    {
                      res+=(solve(pos+1,1,ones+1,s));
                    }
                    else{
                        res+=solve(pos+1,1,ones,s);
                    }
                }
                else{
                      if(i==1)res+=(solve(pos+1,0,ones+1,s));
                      else res+=solve(pos+1,0,ones,s);  
                }
            }
        }
        else if(tight==0){
            for(int i=0;i<=9;i++){
                if(i==1)res+=(solve(pos+1,0,ones+1,s));
                else res+=solve(pos+1,0,ones,s);
            }
        }
        return dp[pos][tight][ones]=res;
    }
    int countDigitOne(int n) {
        string s=to_string(n);

        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,s);

    }
};