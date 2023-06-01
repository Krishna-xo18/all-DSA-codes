class Solution {
public:
  
    int jump(vector<int>& nums) {
    int target=nums.size()-1;
    int alpha=0;
    int count=1;
    while(1){
        if(target==0){
            return count-1;
        }
        if(alpha+nums[alpha]>=target){
            target=alpha;
            alpha=-1;
            count++;
        }
        
        alpha++;
    }
    }
};