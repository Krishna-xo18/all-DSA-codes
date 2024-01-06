class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //sum of two sides is greater than 3rd side
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int sum=nums[i]+nums[j];
                int idx=lower_bound(nums.begin(),nums.end(),sum)-nums.begin();
               ans+=max(0,idx-j-1);
            }
        }
        return ans;
    }
};