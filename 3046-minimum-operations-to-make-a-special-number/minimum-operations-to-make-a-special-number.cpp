class Solution {
public:
    int dp[101][26];
    int solve(int idx ,int number,string &num ){
        if(idx==num.size()){
            if(number%25==0){
                return 0;
            }
            return 1e5;
        }
        if(dp[idx][number]!=-1){
            return dp[idx][number];
        }
        int digit=num[idx]-'0';
        int delete_digit=1+solve(idx+1,number,num);
        //we do (number*10+digit)%25 because for example to check divisibility of 2573 we can check by divisibility of(2500+75 )%25 so we can check the running reminder
        int skip_digit=solve(idx+1,(number*10+digit)%25,num);
        return dp[idx][number]=min(delete_digit,skip_digit);
    }
    int minimumOperations(string num) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,num);
    }
};