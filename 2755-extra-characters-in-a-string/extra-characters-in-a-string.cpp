class Solution {
public:
    int solve(int idx,string &s,map<string ,int>&freq,vector<int>&dp){
        if(idx>=s.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        string check="";
        int ans=INT_MAX;
        for(int curr_idx=idx;curr_idx<s.size();curr_idx++){
            check.push_back(s[curr_idx]);
            int count=0;
            //upto that particular idx check if the formed string is present then the other rightmost part can be solved by recursion 
            if(freq.find(check)==freq.end()){
                 count=check.size()+solve(curr_idx+1,s,freq,dp);
            }
            else{
                count=solve(curr_idx+1,s,freq,dp);
            }
            ans=min(ans,count);
        }
        return dp[idx]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int>dp(s.size(),-1);
        map<string ,int>freq;
        for(auto sexy:dictionary){
            freq[sexy]++;
        }
        return solve(0,s,freq,dp);
    }
};