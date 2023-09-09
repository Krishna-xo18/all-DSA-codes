class Solution {
public:
    int dp[101][101];
    int solve(int idx1,int idx2,int idx3,string &s1,string &s2,string &s3){
        if(idx1==s1.size() && idx2==s2.size() && idx3==s3.size()){
            return 1;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int take1=0;
        if(idx1<s1.size() && s1[idx1]==s3[idx3]){
           take1=solve(idx1+1,idx2,idx3+1,s1,s2,s3);
        }
        int take2=0;
        if(idx2<s2.size() && s2[idx2]==s3[idx3]){
           take2=solve(idx1,idx2+1,idx3+1,s1,s2,s3);
        }
        if(take1==0 && take2==0){
            return dp[idx1][idx2]=0;
        }
        return dp[idx1][idx2]=(take1 || take2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(solve(0,0,0,s1,s2,s3)){
            return true;
        }
        return false;
    }
};