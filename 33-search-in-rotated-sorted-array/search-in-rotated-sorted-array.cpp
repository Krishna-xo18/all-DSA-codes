class Solution {
public: 
    int pivot(vector<int>& nums){
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
        return end;
    }
    int binarysearch(vector<int>& nums,int start,int end,int target){
        int mid=start+(end-start)/2;

        while(start<=end){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivotelement=pivot(nums);

        if(target>=nums[0]){
            return binarysearch(nums,0,pivotelement,target);
        }
        else{
            return binarysearch(nums,pivotelement+1,nums.size()-1,target);
        }
    }
};