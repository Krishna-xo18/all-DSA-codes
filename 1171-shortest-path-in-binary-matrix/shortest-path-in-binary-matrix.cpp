class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //applying dijktras algo
        vector<vector<int>>dis(grid.size(),vector<int>(grid[0].size(),1e9));
        if(grid[0][0]==1){
            return -1;
        }
        map<pair<int,int>,vector<pair<int,int>>>mp;
        vector<int>dx={0,1,-1,1,1,-1,-1,0};
        vector<int>dy={1,0,-1,1,-1,1,0,-1};
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                for(int k=0;k<8;k++){
                    int nrow=i+dx[k];
                    int ncol=j+dy[k];
                    if(nrow>-1 && nrow<m && ncol>-1 && ncol <n && grid[nrow][ncol]==0){
                        mp[{i,j}].push_back({nrow,ncol});
                    }
                }
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});

        dis[0][0]=1;
        while(!pq.empty()){
            auto node=pq.top();
            int distance=node.first;
            int i=node.second.first;
            int j=node.second.second;
            pq.pop();
            vector<pair<int,int>>vec;
            if(mp.find({i,j})!=mp.end()){
                 vec=mp[{i,j}];
            }
           
            for(int k=0;k<vec.size();k++){
                int adjnode_row=vec[k].first;
                int adjnode_col=vec[k].second;
                if(distance+1<dis[adjnode_row][adjnode_col]){
                   dis[adjnode_row][adjnode_col]=distance+1;
                   pq.push({distance+1,{adjnode_row,adjnode_col}});
                }
            }


        }
        if(dis[m-1][n-1]==1e9) return -1;
        return dis[m-1][n-1];
    }
};