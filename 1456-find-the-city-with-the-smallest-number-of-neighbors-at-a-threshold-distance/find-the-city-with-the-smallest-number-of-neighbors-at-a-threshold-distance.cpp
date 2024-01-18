class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>temp(n,vector<int>(n,1e9));
         for(int i=0;i<n;i++){
           temp[i][i]=0;
         }
         for(int i=0;i<edges.size();i++){
             temp[edges[i][0]][edges[i][1]]=edges[i][2];
              temp[edges[i][1]][edges[i][0]]=edges[i][2];
         }
         for(int via=0;via<n;via++){
             for(int i=0;i<n;i++){
                 for(int j=0;j<n;j++){
                     if(temp[i][via]!=1e9 || temp[via][j]!=1e9){
	                    temp[i][j]=min(temp[i][j],temp[i][via]+temp[via][j]);
	                }
                 }
             }
         }
        int final_ans=0;
         int ans=INT_MAX;
         for(int i=0;i<n;i++){
             int reachable=0;
             for(int j=0;j<n;j++){
                if(temp[i][j]<= distanceThreshold && i!=j) reachable++;
             }
             if(reachable<=ans){
                 ans=reachable;
                 final_ans=i;
             }
         }
         return final_ans;
    }
};