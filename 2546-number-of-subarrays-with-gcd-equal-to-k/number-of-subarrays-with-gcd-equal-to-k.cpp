class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
       int count=0;
       int g=1;
      
      for(int i=0;i<nums.size();i++){
          g=gcd(nums[i],nums[i]);
          if(g==k){
              count++;
          }
          for(int j=i+1;j<nums.size();j++){
            g=gcd(g,nums[j]);
            if(g==k){
                count++;
            }
          }
      }
      return count;
    }
    
};