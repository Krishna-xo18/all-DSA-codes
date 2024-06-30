class Solution {
public:
    int dp1[200000];
    int dp2[200000];
    int dp3[200000][2];
    int dp4[200000][2];
    int solve_even(int i,vector<int>&nums){
        if(i>=nums.size())return 0;

           if(dp1[i]!=-1)return dp1[i];
        int take=0;
        int nottake=0;
        if(nums[i]%2==0){
            take=1+solve_even(i+1,nums);
        }
        nottake=solve_even(i+1,nums);
        return dp1[i]=max(take,nottake);

        
    }
      int solve_odd(int i,vector<int>&nums ){
        if(i>=nums.size())return 0;

           if(dp2[i]!=-1)return dp2[i];
        int take=0;
        int nottake=0;
        if(nums[i]%2==1){
            take=1+solve_odd(i+1,nums);
        }
        nottake=solve_odd(i+1,nums);
        return dp2[i]=max(take,nottake);
        
        

        
    }
      int solve_even_odd(int i,vector<int>&nums,int flag ){
        if(i>=nums.size())return 0;
        

        if(dp3[i][flag]!=-1)return dp3[i][flag];

        int take=0;
        int nottake=0;
        if(nums[i]%2==flag){
            take=1+solve_even_odd(i+1,nums,!flag);
        }
        nottake=solve_even_odd(i+1,nums,flag);
        return dp3[i][flag]=max(take,nottake);
        

        
    }
          int solve_odd_even(int i,vector<int>&nums,int flag ){
        if(i>=nums.size())return 0;
        

        if(dp4[i][flag]!=-1)return dp4[i][flag];

        int take=0;
        int nottake=0;
        if(nums[i]%2==flag){
            take=1+solve_odd_even(i+1,nums,!flag);
        }
        nottake=solve_odd_even(i+1,nums,flag);
        return dp4[i][flag]=max(take,nottake);
        
          }
     
    int maximumLength(vector<int>& nums) {
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        memset(dp3,-1,sizeof(dp3));
        memset(dp4,-1,sizeof(dp4));


        int val1=solve_even(0,nums);
        int val2=solve_odd(0,nums);
        int val3=solve_even_odd(0,nums,0);
        int val4=solve_odd_even(0,nums,1);
        return max(max(val1,val4),max(val2,val3));

    }
};