class Solution {
public:
    set<vector<int>>ans ;

    void helper(vector<int>& nums,int start){
        if(start==nums.size()){
            ans.insert(nums);
            return;
        }
        for(int j=start;j<nums.size();j++){
            swap(nums[start],nums[j]);
            helper(nums,start+1);
            //backtrack
            swap(nums[start],nums[j]);

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      helper(nums,0);
       vector<vector<int>>ans1(ans.begin(),ans.end());
        return ans1;
    }
};
 