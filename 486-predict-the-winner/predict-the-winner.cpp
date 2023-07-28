class Solution {
public:
   int solve(int front,int back,vector<int>&nums,bool chance){
       if(front>back){
           return 0;
       }
       int ans=0;
       if(chance){
           ans=max(nums[front]+solve(front+1,back,nums,false),nums[back]+solve(front,back-1,nums,false));
       }
       //took min because min of  negative  num is maximum i.e subtracting and adding val to ply1;
       else{
           ans=min(-1*nums[front]+solve(front+1,back,nums,true),-1*nums[back]+solve(front,back-1,nums,true));
    
       }
       return ans;
   }
    bool PredictTheWinner(vector<int>& nums) {
        bool chance=true;
       return solve(0,nums.size()-1,nums,chance)>=0;
    }
};