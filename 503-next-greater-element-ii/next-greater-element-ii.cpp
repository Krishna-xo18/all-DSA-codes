class Solution {
public:
    vector<int>prefix_greater(vector<int>&nums){
        vector<int>ans;
        stack<int>stk;
        for(int i=nums.size()-1;i>=0;i--){
      
           while(!stk.empty() && stk.top()<= nums[i]){
               stk.pop();
           }
           if(stk.empty()){
               ans.push_back(INT_MIN);
               stk.push(nums[i]);
           }
           else{
               ans.push_back(stk.top());
               stk.push(nums[i]);
           }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
   
    vector<int> nextGreaterElements(vector<int>& nums) {
        int x=nums.size();
        
        vector<int>prefix1=prefix_greater(nums);
        for(int i=0;i<x;i++){
            nums.push_back(nums[i]);
        }
        vector<int>prefix2=prefix_greater(nums);
        vector<int>ans;
       for(int i=0;i<x;i++){
           ans.push_back(max(prefix1[i],prefix2[i]));
       }
       for(int i=0;i<ans.size();i++){
           if(ans[i]==INT_MIN) ans[i]=-1;
       }
       return ans;
    }
};