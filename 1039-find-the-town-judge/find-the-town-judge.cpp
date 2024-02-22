class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      
        vector<int>x(1000,0);
        vector<int>y(1000,0);
         int trustedby,trustedperson;
         for(int i=0;i<trust.size();i++){
          
           trustedby=trust[i][0]-1;
           trustedperson=trust[i][1]-1;
           
                     x[trustedperson]=x[trustedperson]+1;    
                     y[trustedby]=y[trustedby]+1;
                            
            
         }
        int ans=-1;
        
        for(int i=0;i<n;i++){
         
            if(x[i]==n-1 && y[i]==0){
          ans=i+1;
                
            }
        }
      
        return ans;
    }
};