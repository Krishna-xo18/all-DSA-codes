class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses,vector<int>{});
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
             int node=q.front();
             q.pop();
             topo.push_back(node);
             for(int adjnode: adj[node]){
                 indegree[adjnode]--;
                 if(indegree[adjnode]==0){
                     q.push(adjnode);
                 }
             }

        }
     
        if(topo.size()==numCourses){
            return topo;
        }
        return {};
    }
};