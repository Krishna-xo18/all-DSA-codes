class Solution {
public:
        vector<vector<int>>ans;
     void helper (vector<int>& nums,int start,vector<int>temp){    
         if(start==nums.size()){
             ans.push_back(temp);
             return;
         }
         //take             
              temp.push_back(nums[start]);
               helper(nums,start+1,temp);
         //not take
               temp.pop_back();
               helper(nums,start+1,temp);
         
     }


    
    vector<vector<int>> subsets(vector<int>& nums) {

           vector<int>temp;
           helper(nums,0,temp);
          return ans;
    }
};