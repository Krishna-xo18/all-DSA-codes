class Solution
{
    public:
        bool checker(string s)
        {
            for (int i = 0; i < s.size() - 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    return false;
                }
            }
            return true;
        }
    string reorganizeString(string s)
    {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        string ans(s.size(),'0');
        int i=0;
        int j=1;
        int test=0;
        while(i<s.size()){
            int val=pq.top().first;
            while(val!=0 && i<s.size()){
                 ans[i]=pq.top().second;
                 val--;
                 i+=2;
            }
            if(val==0){
                pq.pop();
            }
            else{
                 test=val;
            }
        }
        if(test!=0){
         while(test!=0 &&j<s.size()){
             ans[j]=pq.top().second;
             j+=2;
             test--;
         }
         pq.pop();
        }
    
         while(j<s.size()){
            int val=pq.top().first;
            while(val!=0 && j<s.size()){
                 ans[j]=pq.top().second;
                 j+=2;
                 val--;
            }
             pq.pop();
        }
        
        if(checker(ans)){
            return ans;
        }
        
        return "";
    }
};