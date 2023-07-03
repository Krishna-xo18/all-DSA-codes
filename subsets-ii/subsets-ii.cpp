class Solution {
public:
    set<vector<int>>ans;
    void helper(vector<int>&nums,vector<int>&temp,int start){
        if(start==nums.size()){
          //  sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[start]);
        helper(nums,temp,start+1);
        temp.pop_back();
        helper(nums,temp,start+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        helper(nums,temp,0);
        vector<vector<int>>ans1(ans.begin(),ans.end());
        return ans1;
    }
};