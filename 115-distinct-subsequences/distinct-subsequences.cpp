class Solution {
public:
    int dp[1001][1001];
    int solve(int idx1,int idx2,string &s,string &t){
       if(idx1==s.size()){
           return (idx2==t.size());
       }
       if(dp[idx1][idx2]!=-1){
           return dp[idx1][idx2];
       }
       int take1=0;
       int take2=0;
       int nottake=0;
       if(s[idx1]==t[idx2]){
           take1=solve(idx1+1,idx2+1,s,t);
           take2=solve(idx1+1,idx2,s,t);
       }
       else{
             nottake=solve(idx1+1,idx2,s,t);
       }
       return dp[idx1][idx2]=take1+take2+nottake;

    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};