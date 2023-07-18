class Solution
{
    public:
        int solve(int idx, int target, vector<int> &coins, vector<vector< int>> &dp)
        {
            if (target == 0)
            {
                return 1;
            }
            if (target < 0)
            {
                return 0;
            }
            if (idx == -1)
            {
                return (target == 0);
            }
            if (dp[idx][target] != -1)
            {
                return dp[idx][target];
            }

            int nottake = solve(idx - 1, target, coins, dp);
            int take = 0;
            if (target >= coins[idx])
            {
                take = solve(idx, target - coins[idx], coins, dp);
            }
            return dp[idx][target] = take + nottake;
        }
    int change(int amount, vector<int> &coins)
    {
        vector<vector < int>> dp(coins.size() + 1, vector<int> (amount + 1, -1));
        return solve(coins.size() - 1, amount, coins, dp);
    }
};