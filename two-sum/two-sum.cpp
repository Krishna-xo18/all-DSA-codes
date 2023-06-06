class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>old;
        old=nums;
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int ans1=0;
        int ans2=0;
        while(start<end){
            if((nums[start]+nums[end])==target){
               ans1=nums[start];
               ans2=nums[end];
               break;
            }
            else if(nums[start]+nums[end]<target){
                start++;
            }
            else{
                end--;
            }
        }
        vector<int>finalans;
        for(int i=0;i<old.size();i++){
            if(ans1==old[i]){
              finalans.push_back(i);
            }
            else if(ans2==old[i]){
                finalans.push_back(i);
            }
        }
        return finalans;
    }
};