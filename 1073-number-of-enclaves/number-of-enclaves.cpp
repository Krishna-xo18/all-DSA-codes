class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&board,int m,int n){
      
       vector<int>dx={-1,0,1,0};
       vector<int>dy={0,1,0,-1};
       board[i][j]=2;
       for(int k=0;k<4;k++){
           int nrow=i+dx[k];
           int ncol=j+dy[k];
           
           if(nrow>-1 && nrow<m && ncol>-1 && ncol<n && board[nrow][ncol]==1){
                 board[i][j]=2;
                 dfs(nrow,ncol,board,m,n);
           }
       }
       
   }
    int  solve(vector<vector<int>>& board) {
       
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1){
                     if(i==0 || i==(m-1) || j==0 || j==(n-1)){
                       dfs(i,j,board,m,n);
                      }
                }
            }
        }
        int ans=0;
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1){
                   ans++;
                }
               
            }
        }
        return ans;
        }
    int numEnclaves(vector<vector<int>>& grid) {
        return solve(grid);
    }
};