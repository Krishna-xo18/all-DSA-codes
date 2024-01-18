class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>>dis(heights.size(),vector<int>(heights[0].size(),1e9));
         map<pair<int,int>,vector<pair<int,pair<int,int>>>>mp;
         vector<int>dx={-1,0,1,0};
         vector<int>dy={0,-1,0,1};
        int m=heights.size();
        int n=heights[0].size();
       // vector<vector<int>>vis(heights.size(),vector<int>(heights[0].size(),0));
         for(int i=0;i<heights.size();i++){
             for(int j=0;j<heights[0].size();j++){
                 int effort=INT_MAX;
                 for(int k=0;k<4;k++){
                     int nrow=i+dx[k];
                     int ncol=j+dy[k];
                     if(nrow>-1 && nrow<m && ncol >-1 && ncol<n ){
                         {
                             effort=abs(heights[nrow][ncol]-heights[i][j]);
                          mp[{i,j}].push_back({effort,{nrow,ncol}});
                         }
                        
                     }
                 }
             }
         }
          vector<vector<int>>vis(m,vector<int>(n,0));
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
         pq.push({0,{0,0}});
         dis[0][0]=0;
         while(!pq.empty()){
             auto node=pq.top();
             int effort=node.first;
             int i=node.second.first;
             int j=node.second.second;
             vis[i][j]=1;
             pq.pop();
             vector<pair<int,pair<int,int>>>vec;
             if(mp.find({i,j})!=mp.end()){
                vec=mp[{i,j}];
             }
           
             for(int k=0;k<vec.size();k++){
                 int adjnode_row=vec[k].second.first;
                 int adjnode_col=vec[k].second.second;
                 int wt=vec[k].first;
                  wt=max(effort,wt);
                if(!vis[adjnode_row][adjnode_col] && wt<dis[adjnode_row][adjnode_col]){
                  
                   dis[adjnode_row][adjnode_col]=wt;
                   
                    pq.push({wt,{adjnode_row,adjnode_col}});
                }
             }
         }
         return dis[m-1][n-1];
    }
};