class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>negs;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                negs.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        int count=pos.size();
        vector<int>ans;
        int i=0;
        while(i!=count){
            ans.push_back(pos[i]);
            ans.push_back(negs[i]);
            i++;
        }
        return ans;
    }
};