class Solution {
public:
    int dp[71][71][71];
    int solve(int r1,int c1,int c2,vector<vector<int>>&grid,int m,int n){
        if(r1>=n){
            return 0;
        }
        if(c1>=m || c2>=m || c1<0 || c2<0){
            return -1e9;
        }
        if(dp[r1][c1][c2]!=-1){
            return dp[r1][c1][c2];
        }
        int ans=0;
        if(c1==c2){
           ans+=grid[r1][c1];
        }
        else{
            ans+=grid[r1][c1];
            ans+=grid[r1][c2];
        }
        vector<int>temp;
        temp.push_back(solve(r1+1,c1-1,c2-1,grid,m,n));
        temp.push_back(solve(r1+1,c1-1,c2,grid,m,n));
        temp.push_back(solve(r1+1,c1-1,c2+1,grid,m,n));
        temp.push_back(solve(r1+1,c1,c2-1,grid,m,n));
        temp.push_back(solve(r1+1,c1,c2,grid,m,n));
        temp.push_back(solve(r1+1,c1,c2+1,grid,m,n));
        temp.push_back(solve(r1+1,c1+1,c2-1,grid,m,n));
        temp.push_back(solve(r1+1,c1+1,c2,grid,m,n));
        temp.push_back(solve(r1+1,c1+1,c2+1,grid,m,n));
        ans+=*max_element(temp.begin(),temp.end());
        return dp[r1][c1][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,grid,m,n);
    }
};