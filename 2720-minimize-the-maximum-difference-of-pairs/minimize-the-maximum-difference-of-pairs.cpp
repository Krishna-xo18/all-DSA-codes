class Solution {
public:
    int possible_pairs(vector<int>&nums,int mid){
        int pairs=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=mid){
                i++;
                pairs++;
            }
        }
        return pairs;
    }
    int search(int start,int end,vector<int>&nums,int p){
        int mid=end+(start-end)/2;
        while(start<=end){
          if(possible_pairs(nums,mid)>=p){
              end=mid-1;
          }
          else{
              start=mid+1;
          }
           mid=end+(start-end)/2;
        }
        return start;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        return search(0,nums[nums.size()-1]-nums[0],nums,p);
    }
};