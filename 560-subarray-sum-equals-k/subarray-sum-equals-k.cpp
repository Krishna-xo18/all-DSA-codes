class Solution {
public:
    vector<int> prefix_sum(vector<int>&nums){
     int sum=0;
     vector<int>temp;
     for(int i=0;i<nums.size();i++){
       sum+=nums[i];
       temp.push_back(sum);
     }
     return temp;

    }
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix=prefix_sum(nums);
        unordered_map<int,int>mp;
        int ans=0;
        mp[0]++;
        for(int i=0;i<prefix.size();i++){

           
            if(mp.find(prefix[i]-k)!=mp.end()){
                ans+=mp[prefix[i]-k];
            }
             mp[prefix[i]]++;
        }
        return ans;
    }
};