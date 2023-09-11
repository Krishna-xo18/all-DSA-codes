class Solution {
public:
    int min_distance(int x1,int y1,int x2,int y2){
        return (abs(x1-x2)+abs(y1-y2));
    }
    int solve(int idx,vector<pair<int,int>>&zeros,vector<pair<int,int>>&non_zeros,map<pair<int,int>,int>&mp){
        if(idx==zeros.size()){
            return 0;
        }
        int ans=1e5;
        for(int i=0;i<non_zeros.size();i++){
             int take=1e4;
            if(mp[{non_zeros[i].first,non_zeros[i].second}]>1){
                mp[{non_zeros[i].first,non_zeros[i].second}]--;
                 int x=zeros[idx].first;
                 int y=zeros[idx].second;
                 int x1=non_zeros[i].first;
                 int y1=non_zeros[i].second;
                take=min_distance(x,y,x1,y1)+solve(idx+1,zeros,non_zeros,mp);
                 mp[{x1,y1}]++;
            }
                 ans=min(ans,take);
        }
                 return ans;
       
    }
         
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>>zeros;
        vector<pair<int,int>>non_zeros;
        map<pair<int,int>,int>mp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
                    zeros.push_back({i,j});
                }
                else if(grid[i][j]>1){
                    non_zeros.push_back({i,j});
                    mp[{i,j}]=grid[i][j];
                }
            }
        }
        return solve(0,zeros,non_zeros,mp);
    }
};