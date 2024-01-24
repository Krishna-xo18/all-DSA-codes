class Solution {
public:
    bool floydmarshal(vector<vector<int>>roads,int n,int maxDistance,vector<int>subset){
        vector<vector<int>>temp(n,vector<int>(n,1e9));
        for(int i=0;i<roads.size();i++){
            int x=roads[i][0];
            int y=roads[i][1];
            if(!binary_search(subset.begin(),subset.end(),x) && !binary_search(subset.begin(),subset.end(),y)){
                temp[x][y]=min(temp[x][y],roads[i][2]);
                temp[y][x]=min(temp[y][x],roads[i][2]);
            }
        }
        for(int i=0;i<n;i++){
            temp[i][i]=0;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(temp[i][via]!=1e9 && temp[via][j]!=1e9){
                        temp[i][j]=min(temp[i][via]+temp[via][j],temp[i][j]);
                    }
                }
            }
        }
        vector<int>active;
        for(int i=0;i<n;i++){
            if(!binary_search(subset.begin(),subset.end(),i)){
                active.push_back(i);
            }
        }
        for(int i=0;i<active.size();i++){
            for(int j=i+1;j<active.size();j++){
                if(temp[active[i]][active[j]]>maxDistance){
                    return false;
                }
            }
        }
        return true;
    }
     void helper (vector<int>& nums,int start,vector<int>temp,vector<vector<int>>&ans){    
         if(start==nums.size()){
             ans.push_back(temp);
             return;
         }
          
              temp.push_back(nums[start]);
               helper(nums,start+1,temp,ans);
 
               temp.pop_back();
               helper(nums,start+1,temp,ans);
         
     }
    
    vector<vector<int>> subsets(vector<int>& nums) {

           vector<int>temp;
           vector<vector<int>>ans;
           helper(nums,0,temp,ans);
          return ans;
    }
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<int>temp(n,0);
        for(int i=0;i<temp.size();i++){
            temp[i]=i;
        }
        vector<vector<int>>sub=subsets(temp);
       
        int ans=0;
       
        for(int i=0;i<sub.size();i++){
            if(floydmarshal(roads,n,maxDistance,sub[i])){
                ans++;
            }
        }
        return ans;
    }
};