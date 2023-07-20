class Solution
{
    public:
     //recursive
       int solve1(int idx1,int idx2,string text1,string text2,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0){
            return 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(text1[idx1]==text2[idx2]){
            return 1+solve(idx1-1,idx2-1,text1,text2,dp);
        }
        return dp[idx1][idx2]=max(solve(idx1-1,idx2,text1,text2,dp),solve(idx1,idx2-1,text1,text2,dp));
    }
        int solve(int idx1, int idx2, string text1, string text2, vector<vector < int>> &dp)
        {
           	//shifting of index method shift by 1 all indices i.e -1 will become 0 ,n-1 will become n
            idx1++;
            idx2++;
            for (int i = 0; i <= idx1; i++)
            {
                for (int j = 0; j <= idx2; j++)
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 0;
                    }
                    else if (text1[i - 1] == text2[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[idx1][idx2];
        }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector < int>> dp(text1.size() + 1, vector<int> (text2.size() + 1, 0));
        return solve(text1.size() - 1, text2.size() - 1, text1, text2, dp);
    }
};