class Solution
{
    public:
        int dp[101][101];
    int solve(int start, int end, vector<int> &cuts, int cuts_start, int cuts_end)
    {
        if (cuts_start > cuts_end)
        {
            return 0;
        }
        if (dp[cuts_start][cuts_end] != -1)
        {
            return dp[cuts_start][cuts_end];
        }
        int ans = INT_MAX;
        for (int k = cuts_start; k <= cuts_end; k++)
        {
            ans = min(ans, (end - start) + solve(start, cuts[k], cuts, cuts_start, k - 1) + solve(cuts[k], end, cuts, k + 1, cuts_end));
        }

        return dp[cuts_start][cuts_end] = ans;
    }
    int minCost(int n, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return solve(0, n, cuts, 0, cuts.size() - 1);
    }
};