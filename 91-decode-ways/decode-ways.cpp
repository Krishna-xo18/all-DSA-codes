class Solution {
public:
   int dp[100];
    int solve(int idx,string s){
        if(idx>=s.size()){
            return 1;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }


        //1 take
        int take1=0;
        int take2=0;
        if(s[idx]!='0'){
          take1=solve(idx+1,s);
        }
        if(idx<s.size()-1){
            string s1="";
            s1+=s[idx];
            s1+=s[idx+1];
            cout<<s1<<endl;
            int num=stoi(s1);
            
            if(s[idx]!='0' && num>=1 && num<=26){
                take2=solve(idx+2,s);
            }
        }
        return dp[idx]=take1+take2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};