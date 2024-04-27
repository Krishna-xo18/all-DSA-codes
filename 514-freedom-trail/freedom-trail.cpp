class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,string ring,string key){
        if(j>=key.size()){
            return 0;
        }
        int n=ring.size();
       if(dp[i][j]!=-1)return dp[i][j];
        int take1=1e9;
        int take2=1e9;
        int take3=1e9;
        {
            for(int k=0;k<i;k++){
                if(ring[k]==key[j]){
                  int opt1=(i-k+1)+solve(k,j+1,ring,key);
                   int opt2= (n+k-i+1)+solve(k,j+1,ring,key);
                    take2=min(take2,min(opt1,opt2));
                }
            }
             for(int k=i;k<ring.size();k++){
                if(ring[k]==key[j]){
                    int opt1=(k-i+1)+solve(k,j+1,ring,key);
                    int opt2=(n-k+i+1)+solve(k,j+1,ring,key);
                    take3=min(take3,min(opt1,opt2));
                }
            }
        }
        return dp[i][j]=min({take1,take2,take3});
    }
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,ring,key);
    }
};