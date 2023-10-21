class Solution {
public:
    int dp[301][301];
    int solve(int i,int j,vector<vector<int>>& matrix){
        if(i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(i,j+1,matrix);
        int down=solve(i+1,j,matrix);
        int diagnol=solve(i+1,j+1,matrix);
        
          return dp[i][j]=(1+min(right,min(down,diagnol)));
        
        
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1)
                ans+=solve(i,j,matrix);
            }
        }
        return ans;
    }
};