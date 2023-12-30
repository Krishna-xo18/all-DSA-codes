class Solution {
public:
    int dp[301][11];
    int solve(int idx,int d,vector<int>&jobDifficulty){
       if(d <= 0 && idx >= jobDifficulty.size()) return 0;
        if(d <= 0 || idx >= jobDifficulty.size()) return 1e9;

      if(dp[idx][d]!=-1){
          return dp[idx][d];
      }
      int maxi=0;
      int ans=1e9;
      for(int i=idx;i<jobDifficulty.size();i++){
          maxi=max(maxi,jobDifficulty[i]);
          int take=maxi+solve(i+1,d-1,jobDifficulty);
          
          ans=min(ans,take);
      }
      
      return dp[idx][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d){
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,d,jobDifficulty);
    }
};