class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int>vis(n,0);
        vis[0]=1;
        map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<meetings.size();i++){
            mp[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
             mp[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        mp[0].push_back({firstPerson,0});
        queue<pair<int,int>>q;
        vector<int>time_received(n,INT_MAX);
        q.push({0,0});
        time_received[0]=0;

        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            vis[node]=1;

            q.pop();
            vector<pair<int,int>>temp=mp[node];
            for(auto adjnode: temp){
                if( time<=adjnode.second &&adjnode.second<time_received[adjnode.first]){
                    q.push({adjnode.first,adjnode.second});
                    time_received[adjnode.first]=adjnode.second;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<vis.size();i++){
            if(time_received[i]!=INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};