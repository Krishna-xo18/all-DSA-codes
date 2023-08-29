class Solution {
public:
    bool is_possible(int divisor,vector<int>&nums,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(ceil((double)nums[i]/(double)divisor));
        }
        if(sum<=threshold){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
        int mid=start+(end-start)/2;
        while(start<=end){
            if(is_possible(mid,nums,threshold)){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return start;
    }
};