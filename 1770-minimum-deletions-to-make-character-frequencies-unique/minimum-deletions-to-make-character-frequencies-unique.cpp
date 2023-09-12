class Solution
{
    public:
        int minDeletions(string s)
        {
            unordered_map<char, int> mp;
            set<int> freq;
            for (int i = 0; i < s.size(); i++)
            {
                mp[s[i]]++;
            }
            priority_queue<pair<int, char>> pq;
            for (auto x: mp)
            {
                pq.push({ x.second,
                    x.first });
            }
            int ans = 0;
            while (!pq.empty())
            {
                int fq = pq.top().first;
                pq.pop();
                if (freq.find(fq) == freq.end())
                {
                    freq.insert(fq);
                }
                else
                {
                    while (freq.find(fq) != freq.end() && fq > 0)
                    {
                        ans++;
                        fq--;
                    }
                    freq.insert(fq);
                }
            }
            return ans;
        }
};