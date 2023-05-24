class Solution {
public:
    vector<vector<int>>ans ;

    void helper(vector<int>& nums,int start){
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=start;j<nums.size();j++){
            swap(nums[start],nums[j]);
            helper(nums,start+1);
            //backtrack
            swap(nums[start],nums[j]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0);
        return ans;
    }
};