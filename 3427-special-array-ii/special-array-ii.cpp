class Solution {
public:

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>flags;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2){
                flags.push_back(i);
            }
        }
        
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            int idx1=lower_bound(flags.begin(),flags.end(),x+1)-flags.begin();
            if(x==y || idx1>=flags.size())ans.push_back(true);
           else if(flags[idx1]>=x && flags[idx1]<=y){
               ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};