class Solution {
public:
    int dp[501][501];
    int solve(int idx1,int idx2,string s1,string s2){
        if(idx1==-1 || idx2==-1){
            return 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(s1[idx1]==s2[idx2]){
            return dp[idx1][idx2]=1+solve(idx1-1,idx2-1,s1,s2);
        }
        return dp[idx1][idx2]= max(solve(idx1-1,idx2,s1,s2),solve(idx1,idx2-1,s1,s2));

    }
    int lcs(string s1,string s2){
       int len1=s1.size();
       int len2=s2.size();
       
       memset(dp,-1,sizeof(dp));
       return solve(len1-1,len2-1,s1,s2);
    }
    int minDistance(string word1, string word2) {
        //same as min number of steps to amke string palinrome;
        if(word1==word2){
            return 0;
        }
        int len=word1.size()+word2.size();
        int ans=len-2*lcs(word1,word2);
    
        return ans;
    }
};