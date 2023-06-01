class Solution {
public:
    bool canJump(vector<int>& nums) {
      int target=nums.size()-1;
    int alpha=0;
    int count=1;
    while(1){
        if(target==0){
            return true;
        }
        if(alpha==target-1 && alpha+nums[alpha]<target){
            return false;
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