class Solution {
public:
 int get_pivot(vector<int>& nums){
        int start=0;
        int end=nums.size()-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            if(nums[start]==nums[end] && start!=end){
                int val=nums[start];
                while(nums[start]==val && start<end){
                    start++;
                }
                while(nums[end]==val && start<end){
                    end--;
                }
            }
            else if(nums[mid]>=nums[0]){
               start=mid+1;
            }
            else if(nums[mid]<=nums[nums.size()-1]){
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return end;
    }
    bool binarysearch(int start,int end,vector<int>&nums,int target){
        int mid=end+(start-end)/2;
        while(start<=end){
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]<target){
               start=mid+1;
            }
            else if(nums[mid]>target){
                   end=mid-1;
            }
            mid=end+(start-end)/2;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        
        int piv=get_pivot(nums);
        return (binarysearch(0,piv,nums,target) || binarysearch(piv+1,nums.size()-1,nums,target));
    }
};