class Solution {
public:
    vector<int> prefix_multi(vector<int>&nums){
        int num=1;
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(num);
            num=num*nums[i];
        }
        return temp;
    }
     vector<int> suffix_multi(vector<int>&nums){
        int num=1;
        vector<int>temp;
        for(int i=nums.size()-1;i>=0;i--){
            temp.push_back(num);
            num=num*nums[i];
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix=prefix_multi(nums);
        vector<int>suffix=suffix_multi(nums);
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
           ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;
    }
};