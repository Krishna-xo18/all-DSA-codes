class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        int row=grid.size();
        int column=grid.size();
        for(int i=0;i<row;i++){
            mp[grid[i]]++;
        }
          int ans=0;
        for(int i=0;i<column;i++){
            vector<int>temp;
            for(int j=0;j<row;j++){
                temp.push_back(grid[j][i]);
            }
            
           ans+= mp[temp];
        }
        for(auto element:mp){
            cout<<element.second<<" "; 
        }
        
        return ans;
    }
};