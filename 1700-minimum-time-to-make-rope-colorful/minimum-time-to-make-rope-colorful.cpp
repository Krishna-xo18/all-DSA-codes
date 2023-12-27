class Solution {
public:
    int minc(string& c,int ind,char prev,vector<int>& t, vector<vector<int>>& dp){
        if(ind==c.size()) return 0;
        
        if(dp[ind][prev-'a'] != -1) return dp[ind][prev-'a'];
        
        if(c[ind]==prev) return dp[ind][prev-'a']=minc(c,ind+1,prev,t,dp)+t[ind];
        
        int take=minc(c,ind+1,c[ind],t,dp);
        int notTake=minc(c,ind+1,prev,t,dp)+t[ind];
        
        return dp[ind][prev-'a']=min(take,notTake);
    }
    int minCost(string colors, vector<int>& neededTime) {
        vector<vector<int>> dp(colors.size()+1,vector<int>(27,-1));
        return minc(colors,0,'{',neededTime,dp);
    }
};