class Solution {
public:
  
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                         q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            auto node=q.front();
            int i=node.first.first;
            int j=node.first.second;

            int t=node.second;
            q.pop();
            vis[i][j]=1;
             vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        for(int k=0;k<4;k++){
               int nrow=i+dx[k];
               int ncol=j+dy[k];
               
               if(nrow>-1 && nrow<mat.size()&& ncol>-1 && ncol<mat[0].size() && !vis[nrow][ncol] && mat[nrow][ncol]!=0){
                ans[nrow][ncol]=t+1;
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},t+1});
               }
           }
          

        }
         return ans;
    }
};