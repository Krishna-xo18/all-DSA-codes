class Solution
{
    public:
        unsigned int dp[1001];
    int solve( int target, vector<int> &nums)
    {
        
        if (target < 0)
        {
            return 0;
        }
        
        if (dp[target] != -1)
        {
            return dp[target];
        }
        int take = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            take += solve( target - nums[i], nums);
        }
        return dp[target] = take;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        memset(dp, -1, sizeof(dp));
        dp[0]=1;
        return solve( target, nums);
    }
};