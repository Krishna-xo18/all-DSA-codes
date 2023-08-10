class Solution {
public:
     int dp[1000][1000];
    int solve(int idx,int paid,vector<int>&days,vector<int>&costs){
        if(idx==days.size()){
         return 0;
        }
        if(dp[idx][paid]!=-1){
            return dp[idx][paid];
        }
        int take1=1e5;
        int take2=1e5;
        int take3=1e5;
        if(days[idx]>=paid){
            take1=costs[0]+solve(idx+1,days[idx]+1,days,costs);
        }
        else{
            take1=solve(idx+1,paid,days,costs);
        }
         if(days[idx]>=paid){
            take2=costs[1]+solve(idx+1,days[idx]+7,days,costs);
        }
        else{
            take2=solve(idx+1,paid,days,costs);
        }
         if(days[idx]>=paid){
            take3=costs[2]+solve(idx+1,days[idx]+30,days,costs);
        }
        else{
            take3=solve(idx+1,paid,days,costs);
        }
        int ans=min(take1,min(take2,take3));
        return dp[idx][paid]= ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,days,costs);
    }
};