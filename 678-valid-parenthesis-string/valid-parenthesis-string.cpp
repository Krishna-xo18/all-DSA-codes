class Solution {
public:
   int dp[101][101];
    bool isvalid(int i,int j, string s){
        if(i>j){
            return true;
        }
        if(s[i]==')' || s[j]=='('){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=false;
         if(s[i]=='*' && s[j]!='*'){
            s[i]='(';
            int take1=isvalid(i,j,s);
            int take2=isvalid(i+1,j,s);
            ans=(take1 || take2);
        }
        else if(s[j]=='*' && s[i]!='*'){
             s[j]=')';
            int take1=isvalid(i,j,s);
            int take2=isvalid(i,j-1,s);
            ans=(take1 || take2);
        }
        else{
            int take1=isvalid(i+1,j-1,s);
            ans=(take1);
        }

        for(int k=i+1;k<j;k++){
            ans=ans|| (isvalid(i,k,s) && isvalid(k+1,j,s));
        }
       
        return dp[i][j]=ans;
    }
    bool checkValidString(string s) {
        // lastinsert ( =1 ,* =2, )=3;
        int j=s.size();
        if(j==1){
            return (s[0]=='*');
        }
        memset(dp,-1,sizeof(dp));
        return isvalid(0,j-1,s);
    }
};