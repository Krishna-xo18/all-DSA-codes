class Solution
{
    public:
        int atMostSum(vector<int> &arr, int k)
        {
            int sum = 0;
            int cnt = 0, maxcnt = 0;
            int n = arr.size();
            for (int i = 0; i < n; i++)
            {
                if ((sum + arr[i]) <= k)
                {
                    sum += arr[i];
                    cnt++;
                }
                else
                {
                    sum = sum - arr[i - cnt] + arr[i];
                }
                maxcnt = max(cnt, maxcnt);
            }
            return maxcnt;
        }
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        map<int, vector < int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            {
                mp[nums[i]].push_back(i);
            }
        }
        map<int, vector < int>> mp_1;
        for (auto element: mp)
        {
            auto v = element.second;
            vector<int> temp;
            if (v.size() > 1)
            {
                for (int i = 1; i < v.size(); i++)
                {
                    temp.push_back(v[i] - v[i - 1] - 1);
                }
                mp_1[element.first] = temp;
            }
        }
        int ans = 0;
        for (auto alpha: mp_1)
        {
            ans = max(ans, atMostSum(alpha.second, k));
        }
        return ans + 1;
    }
};