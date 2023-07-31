class Solution
{
    public:
        string merge2(string str1, string str2)
        {
            if (str1.find(str2) != string::npos) return str1;
            int sz1 = str1.size();
            int sz2 = str2.size();
            int sz = min(sz1, sz2);

            for (int i = sz; i >= 0; i--)
            {
                if (str1.substr(sz1 - i) == str2.substr(0, i))
                {
                    return str1 + str2.substr(i);
                }
            }
            return str1 + str2;
        }
    string merge(string a, string b, string c)
    {
        string s = merge2(a, b);
        return merge2(s, c);
    }
    int min(int a, int b)
    {
        if (a < b)
        {
            return a;
        }
        return b;
    }
    string minimumString(string a, string b, string c)
    {
        vector<string> ans;

        ans.push_back(merge(a, b, c));
        ans.push_back(merge(a, c, b));
        ans.push_back(merge(b, a, c));
        ans.push_back(merge(c, a, b));
        ans.push_back(merge(b, c, a));
        ans.push_back(merge(c, b, a));
        int mini = INT_MAX;
        for (int i = 0; i < ans.size(); i++)
        {
            mini = min(mini, ans[i].size());
        }
        vector<string> final;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i].size() == mini)
            {
                final.push_back(ans[i]);
            }
        }
        sort(final.begin(), final.end());
        return final[0];
    }
};