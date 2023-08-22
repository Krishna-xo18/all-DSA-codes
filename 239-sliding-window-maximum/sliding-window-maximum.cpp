class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int i=0;;
        for(int j=0;j<k;j++){
            while(!dq.empty() && dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
        }
        ans.push_back(dq.front());
        for(int j=k;j<nums.size();j++){
           if(nums[j-k]==dq.front()){
               dq.pop_front();
           }
           while(!dq.empty() && dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};