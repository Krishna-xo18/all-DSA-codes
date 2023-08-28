class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=1;
        int ans=INT_MIN;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        vector<int>nums1;
        for(auto it=s.begin();it!=s.end();it++){
             nums1.push_back(*it);
        }
        nums=nums1;
        if(nums.size()==0 || nums.size()==1){
            return nums.size();
        }
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]+1 ){
                count++;
                ans=max(ans,count);
            }
            else{
                count=1;
                ans=max(ans,count);
            }
        }
        return ans;
    }
};