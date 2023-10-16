class Solution {
public:
    vector<pair<int,int>> preffix_max(vector<int>&nums){
        stack<pair<int,int>>stk;
        stk.push({nums[0],0});
        vector<pair<int,int>>ans;
        ans.push_back({nums[0],0});
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=stk.top().first){
                stk.push({nums[i],i});
            }
            ans.push_back({stk.top().first,stk.top().second});
        }
        return ans;
    }
     vector<pair<int,int>> preffix_min(vector<int>&nums){
        stack<pair<int,int>>stk;
        stk.push({nums[0],0});
        vector<pair<int,int>>ans;
        ans.push_back({nums[0],0});
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=stk.top().first){
                stk.push({nums[i],i});
            }
            ans.push_back({stk.top().first,stk.top().second});
        }
        return ans;
    }
    vector<pair<int,int>> sufffix_min(vector<int>&nums){
        stack<pair<int,int>>stk;
        stk.push({nums[nums.size()-1],nums.size()-1});
        vector<pair<int,int>>ans;
        ans.push_back({nums[nums.size()-1],nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<=stk.top().first){
                stk.push({nums[i],i});
            }
            ans.push_back({stk.top().first,stk.top().second});
        }
      reverse(ans.begin(),ans.end());
        return ans;
    }
     vector<pair<int,int>> sufffix_max(vector<int>&nums){
        stack<pair<int,int>>stk;
        stk.push({nums[nums.size()-1],nums.size()-1});
        vector<pair<int,int>>ans;
        ans.push_back({nums[nums.size()-1],nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=stk.top().first){
                stk.push({nums[i],i});
            }
            ans.push_back({stk.top().first,stk.top().second});
        }
      reverse(ans.begin(),ans.end());
        return ans;
    }
    
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<pair<int,int>>prefix_max=preffix_max(nums);
       vector<pair<int,int>>suffix_min=sufffix_min(nums);
         vector<pair<int,int>>prefix_min=preffix_min(nums);
         vector<pair<int,int>>suffix_max=sufffix_max(nums);
       for(int i=0;i+indexDifference<nums.size();i++){
           if(abs(prefix_max[i].first-suffix_min[i+indexDifference].first)>=valueDifference){
               {
                  
                   return {prefix_max[i].second,suffix_min[i+indexDifference].second};
               }
           }
       }
        for(int j=nums.size()-1;j-indexDifference>=0;j--){
             if(abs(prefix_min[j-indexDifference].first-suffix_max[j].first)>=valueDifference){
               {
                   return {prefix_min[j-indexDifference].second,suffix_max[j].second};
               }
           }
        }
        return {-1,-1};
          
    }
};