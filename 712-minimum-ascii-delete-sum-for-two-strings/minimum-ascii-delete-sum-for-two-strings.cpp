class Solution
{
    public:
        int solve(string text1, string text2)
        {
            vector<vector < int>> dp(text1.size() + 1, vector<int> (text2.size() + 1, 0));
           	//shifting of index method shift by 1 all indices i.e -1 will become 0 ,n-1 will become n
            int idx1 = text1.size() - 1;
            int idx2 = text2.size() - 1;
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
                        dp[i][j] = text1[i - 1] + dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            int ans = dp[idx1][idx2];
            return ans;
        }
    int summer(string txt)
    {
        int txtASCII_Sum = 0;

        for (int i = 0; i < txt.size(); i++)
        {
            txtASCII_Sum = txtASCII_Sum + txt[i];
        }

        return txtASCII_Sum;
    }
    int minimumDeleteSum(string s1, string s2)
    {

        return summer(s1) + summer(s2) - 2* solve(s1, s2);
    }
};