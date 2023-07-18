class Solution {
public:
    int solve(int idx,int target,vector<int>&nums){
        if(idx==0){
            if(target-nums[idx]==0  && target+nums[idx]==0){
                return 2;
            }
             if(target-nums[idx]==0  || target+nums[idx]==0){
                return 1;
            }
            return 0;
        }
        int plus=solve(idx-1,target+nums[idx],nums);
        int minus=solve(idx-1,target-nums[idx],nums);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums.size()-1,target,nums);
    }
};