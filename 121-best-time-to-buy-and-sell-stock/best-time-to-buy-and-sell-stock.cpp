class Solution {
public:
    vector<int>prefix_max(vector<int>&nums){
        stack<int>stk;
        stk.push(-1);
        vector<int>ans;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            ans.push_back(stk.top());
            if(nums[i]>=stk.top()){
                stk.push(nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<int>prefix=prefix_max(prices);
        int ans=0;
        for(int i=0;i<prices.size();i++){
            ans=max(ans,prefix[i]-prices[i]);
        }
       return ans;
    }
};