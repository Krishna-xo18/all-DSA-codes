class Solution {
public:

    int getpivot(vector<int>&nums){
        int start=0;
        int end=nums.size()-1;
        int mid=start+(end-start)/2;
        while(start<=end){
          if(nums[mid]>=nums[0]){
              start=mid+1;
          }
          else if(nums[mid]<=nums[nums.size()-1]){
              end=mid-1;
          }
           mid=start+(end-start)/2;
           
        }
        return start;
    }
    int findMin(vector<int>& nums) {
        int pivot= getpivot(nums);
        if(pivot==nums.size()|| pivot==0){
            return nums[0];
        }
        return nums[pivot];
    }
};