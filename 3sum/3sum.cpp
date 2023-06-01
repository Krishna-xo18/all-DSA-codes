class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
          int k=nums.size()-1;
          int j=i+1;
          while(j<k){
            if(nums[i]+nums[j]+nums[k]==0){
              ans.insert({nums[i],nums[j],nums[k]});
              j++;
              k--;
            }
            else if(nums[i]+nums[j]+nums[k]<0){
              j++;
            }
            else{
              k--;
            }
          }
        }
          vector<vector<int>>ans1(ans.begin(),ans.end());
          return ans1;
        }
    
};