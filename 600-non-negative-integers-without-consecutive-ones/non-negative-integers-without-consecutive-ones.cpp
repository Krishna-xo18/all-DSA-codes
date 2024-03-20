class Solution {
public:
    int dp[40][40][40][2];
 string DecimalToBinary(int num) 
{ 
    string str; 
      while(num){ 
      if(num & 1) // 1 
        str+='1'; 
      else // 0 
        str+='0'; 
      num>>=1; // Right Shift by 1   
    }     
      return str; 
} 
  
    int solve(int pos,int prev,int ones,int tight,string s){
        if(pos==s.size())
        {
             return 1;
        }
        if(dp[pos][prev][ones][tight]!=-1){
            return dp[pos][prev][ones][tight];
        }
        int res=0;
        if(tight==1){
            if(s[pos]=='0'){
               res+=solve(pos+1,0,ones,1,s);
            }
            else if(s[pos]=='1' ){
              if(prev==0) res+=solve(pos+1,1,ones+1,1,s);
               res+=solve(pos+1,0,ones,0,s);
            }
             
        }
        else if(tight==0){
            if(prev==0)res+=solve(pos+1,1,ones+1,0,s);
            res+=solve(pos+1,0,ones,0,s);
        }
        return dp[pos][prev][ones][tight]=res;
    }
    int findIntegers(int n) {
       string str=DecimalToBinary(n);
        //pos 10 prev 10 tight 2 ones 10
        reverse(str.begin(),str.end());
    
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,1,str);
       
    }
};