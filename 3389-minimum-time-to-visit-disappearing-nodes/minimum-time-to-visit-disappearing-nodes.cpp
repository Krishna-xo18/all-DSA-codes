class Solution {
public:
      

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
   
        vector<int>dis(n,INT_MAX);
        map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]!=edges[i][1]){
                mp[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            mp[edges[i][1]].push_back({edges[i][0],edges[i][2]});
       }
            
        }
       priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,-1}});
        dis[0]=0;
        while(!q.empty()){
            auto node=q.top();
            int to=node.second.first;
            int parent=node.second.second;
            int t=node.first;
             
            q.pop();
          if(dis[to]<t)continue;
            for(int i=0;i<mp[to].size();i++){
                if(mp[to][i].first!=parent && disappear[mp[to][i].first]>t+mp[to][i].second && t+mp[to][i].second<dis[mp[to][i].first]){
                    dis[mp[to][i].first]=t+mp[to][i].second;
                    q.push({t+mp[to][i].second,{mp[to][i].first,to}});
                }
            }
        }
        for(int i=0;i<dis.size();i++){
            if(dis[i]== INT_MAX)dis[i]=-1;
        }
        return dis;
    }
};