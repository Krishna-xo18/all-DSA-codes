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
            int idx2=lower_bound(flags.begin(),flags.end(),y)-flags.begin();
            if(x==y )ans.push_back(true);
           else if(idx1==idx2 ){
               if(idx1<flags.size() && idx2<flags.size() && flags[idx1]>=x+1 && flags[idx1]<=y)ans.push_back(false);
               else ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};