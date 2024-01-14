class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<flights.size();i++){
            int from=flights[i][0];
            int to=flights[i][1];
            int price=flights[i][2];
            mp[from].push_back({to,price});
        }
         queue<pair<int,pair<int,int>>>q;
         vector<int>dis(n,1e9);
         q.push({0,{src,k}});
         dis[src]=0;
         while(!q.empty()){
             auto node=q.front();
             int price=node.first;
             int val=node.second.second;
             int to=node.second.first;
             q.pop();
              vector<pair<int,int>>vec;
              if(mp.find(to)!=mp.end()){
                  vec=mp[to];
              }
             
             for(int i=0;i<vec.size();i++){
                 if(val>=0 && price+vec[i].second<dis[vec[i].first])
                 {
                    dis[vec[i].first]=price+vec[i].second;
                     q.push({dis[vec[i].first],{vec[i].first,val-1}});
                 }
             }
         }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};