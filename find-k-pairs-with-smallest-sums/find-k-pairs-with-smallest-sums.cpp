class Solution {
public:
     int min(int k,int m){
         if(k<=m){
             return k;
         }
         return m;
     }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         priority_queue<pair<int, pair<int,int>>>pq;
   
      int m=nums1.size();
      int n=nums2.size();
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                     pq.push({sum,{nums1[i],nums2[j]}});
                }
                 else if(pq.size()==k and nums1[i]+nums2[j]<=pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else{
                    break;
                }
               
            }
        }
        vector<vector<int>>ans;
        while(k!=0 && !pq.empty()){
             vector<int>alpha;
             alpha.push_back(pq.top().second.first);
             alpha.push_back(pq.top().second.second);
             pq.pop();
            k--;
            ans.push_back(alpha);
        }
        return ans;
    }
};