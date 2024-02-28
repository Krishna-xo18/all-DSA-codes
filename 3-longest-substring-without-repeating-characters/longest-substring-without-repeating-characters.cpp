class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            if(s.size()==0){
                return 0;
            }
            int i = 0;
            int j = 0;
            int count = 0;
            map<char, int> mp;
            int ans = 0;
            while (j < s.size())
            {

                if (mp.find(s[j]) == mp.end())
                {
                    count++;
                }
                mp[s[j]]++;
                
                    while ((j - i + 1) > count)
                    {
                        mp[s[i]]--;
                        if (mp[s[i]] == 0)
                        {
                            mp.erase(s[i]);
                            count--;
                        }
                        i++;
                    }
                
                if (j - i + 1 == count)
                {
                    ans = max(ans, count);
                }
                j++;
            }
            return ans;
        }
};