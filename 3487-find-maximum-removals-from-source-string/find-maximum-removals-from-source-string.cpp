class Solution {
public:
    int solve(int i,int j,string &source,string &pattern,vector<int>&target,vector<vector<int>>&dp){
        if(source.size()-i<pattern.size()-j)return 1e9;
        if(j>=pattern.size() ){
            return 0;
        }
        if(i>=source.size()){
            return 1e9;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        int ans=1e9;
        if(source[i]==pattern[j]){
        if(!binary_search(target.begin(),target.end(),i)) ans=min(ans,solve(i+1,j+1,source,pattern,target,dp));
        else ans=min(ans,1+solve(i+1,j+1,source,pattern,target,dp));
        }
        ans=min(ans,solve(i+1,j,source,pattern,target,dp));
       return dp[i][j]=ans;

    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
       vector<vector<int>>dp(source.size()+1,vector<int>(pattern.size(),-1));
       return targetIndices.size()-solve(0,0,source,pattern,targetIndices,dp);
    }
};