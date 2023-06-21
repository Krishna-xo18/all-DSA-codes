class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         priority_queue<long long int, vector<long long int>, greater<long long int> > pq;

         for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix.size();j++){
                 pq.push(matrix[i][j]);
             }
         }
       long long  int ans;
         while(k!=0){
              ans=pq.top();
             k--;
             pq.pop();
         }
         return ans;
    }
};