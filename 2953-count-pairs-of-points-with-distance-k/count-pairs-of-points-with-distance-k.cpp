class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>,int>mp;
       
        for(int i=0;i<coordinates.size();i++){
            mp[{coordinates[i][0],coordinates[i][1]}]++;
           
        }
        vector<pair<int,int>>temp;
        for(auto x:mp){
            temp.push_back(x.first);
        }
         long long int ans=0;
         if(k==0){
             for(auto it : mp){
                ans += it.second * 1ll * (it.second - 1) / 2; 
            }
            return ans;
         }
       
        for(int i=0;i<temp.size();i++){
            int x=temp[i].first;
            int y=temp[i].second;
            for(int j=0;j<=k;j++){
                int x_res=j;
                int y_res=k-j;
                
                int x_val=x^x_res;
                int y_val=y^y_res;
                if(mp.find({x_val,y_val})!=mp.end()){
             
                  {
                      long long int alpha=mp[{x,y}];
                     long long  int beta=mp[{x_val,y_val}];
                      ans+=(long long )(alpha*beta);
                  }
                }
            }
        }
        return ans/2;
    }
};