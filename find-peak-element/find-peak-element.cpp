class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid=start+(end-start)/2;
         int n=nums.size();
        if(n==1||n==0) return 0;
        if(nums[0]>nums[1]) return 0;
        while(start<=end && mid!=0 && mid!=nums.size()-1){
            if(nums[mid]<=nums[mid+1]){
              start=mid+1;
            }
            else if(nums[mid-1]>=nums[mid]){
                end=mid-1;
            }
            else{

                return mid;
            }
            mid=start+(end-start)/2;
        }

        return end;
    }
};