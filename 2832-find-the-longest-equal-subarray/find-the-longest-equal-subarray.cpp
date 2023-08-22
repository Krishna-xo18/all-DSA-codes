class Solution
{
    public:
        int atMostSum(vector<int> &arr, int k)
        {
            int i=0;
            int j=0;
            int sum=0;
            int ans=0;
            while(j<arr.size()){
              sum+=arr[j];
              if(sum<=k){
                 ans=max(ans,j-i+1);
              }
              if(sum>k){
                 while(sum>k){
                     sum-=arr[i];
                     i++;
                 }
              }
              j++;
            }
            return ans;
        }
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        unordered_map<int, vector < int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            {
                mp[nums[i]].push_back(i);
            }
        }
        unordered_map<int, vector < int>> mp_1;
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