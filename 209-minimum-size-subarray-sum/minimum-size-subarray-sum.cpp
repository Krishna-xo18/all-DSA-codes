class Solution {
public: 
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int ans=INT_MAX;
        int var_sum=0;
        for(auto x:nums){
            var_sum+=x;
        }
        if(var_sum<target){
            return 0;
        }
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                  ans=min(ans,j-i+1);
                i++;
            }
           
            j++;
        }
        return ans;
    }
};