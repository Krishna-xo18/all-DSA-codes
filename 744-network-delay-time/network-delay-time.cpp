class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
             int source=times[i][0];
             int target=times[i][1];
             int wt=times[i][2];
             adj[source].push_back({target,wt});
        }
        queue<pair<int,int>>q;
        q.push({0,k});
        dis[k]=0;
        while(!q.empty()){
            auto node=q.front();
            int source=node.second;
            int wt=node.first;
            q.pop();
            auto vec=adj[source];
            for(int i=0;i<vec.size();i++){
                if(vec[i].second+wt<dis[vec[i].first]){
                    dis[vec[i].first]=vec[i].second+wt;
                    q.push({dis[vec[i].first],vec[i].first});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<dis.size();i++){
            if(dis[i]==1e9){
                return -1;
            }
            maxi=max(maxi,dis[i]);
        }
        return maxi;

    }
};