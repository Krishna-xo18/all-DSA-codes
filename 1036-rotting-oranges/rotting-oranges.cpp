class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                        q.push({{i,j},0});
                }
                
            }
        }
     
        int time=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;

            int t=q.front().second;    
            q.pop();
            time=max(time ,t);
           for(int k=0;k<4;k++){
               int nrow=i+dx[k];
               int ncol=j+dy[k];
               if(nrow>-1 && nrow<m && ncol>-1 && ncol<n && grid[nrow][ncol]==1){
                   grid[nrow][ncol]=2;
                   q.push({{nrow,ncol},t+1});
               }
           }
        }
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
    }
};