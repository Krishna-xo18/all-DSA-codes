class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
             mp2[t[i]]++;
        }
        int ans=0;
        for(auto x: mp1){
            char ch=x.first;
            int occur=x.second;
            int curr=0;
            if(mp2.find(ch)!=mp2.end()){
                curr=mp2[ch];
            }
            if(curr<occur){
               ans+=(occur-curr);
            }
        }
        return ans;
    }
};