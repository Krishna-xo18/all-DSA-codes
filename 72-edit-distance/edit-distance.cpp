class Solution {
public:
    int dp[501][501];
    int solve(int idx1,int idx2,string &word1,string &word2){
        if(idx1==word1.size()){
            return word2.size()-idx2;
        }
        if(idx2==word2.size()){
            return word1.size()-idx1;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int nottake=1e4;
        if(word1[idx1]==word2[idx2]){
          //if same skip to next idx
          nottake=solve(idx1+1,idx2+1,word1,word2);
        }
        //insert--> we got that index then check for other one
        int insert=1+solve(idx1,idx2+1,word1,word2);
        //we will delete that char and check if other char is equal
        int del=1+solve(idx1+1,idx2,word1,word2);
        //replace-->normal one, replace that positioned char
        int replace=1+solve(idx1+1,idx2+1,word1,word2);

        return dp[idx1][idx2]=min(min(nottake,insert),min(del,replace));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2);
    }
};