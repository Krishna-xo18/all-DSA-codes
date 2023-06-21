class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,int>>pq;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
          mp[s[i]]++;
        }
        for(auto element:mp){
            pq.push(make_pair(element.second,element.first));
        }
        string ans="";
        while(!pq.empty()){
            char alpha=pq.top().second;
            int occurence=pq.top().first;
            string s2(occurence,alpha);
            ans+=s2;
            pq.pop();
        }
        return ans;
    }
};