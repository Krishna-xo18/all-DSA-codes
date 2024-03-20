class Solution {
public:
    int dp[10][2][10];


    int solve(int pos,int tight,int zeros,vector<string>&digits,string s){
        if(pos==s.size()) return 1;
        if(dp[pos][tight][zeros]!=-1){
            return dp[pos][tight][zeros];
        }
        int res=0;
        if(tight==1){
            for(int i=0;i<digits.size();i++){
                int n=stoi(digits[i]);
                if(n==0 && zeros==0 && pos==0){
                    for(int i=1;i<=s.size()-1;i++){
                        res+=(solve(pos+i,0,zeros+i,digits,s));
                    }
                }
                else if(n!=0 && n<s[pos]-'0')res+=(solve(pos+1,0,zeros,digits,s));
                else if(n!=0 && n==s[pos]-'0') res+=(solve(pos+1,1,zeros,digits,s));
                
            }
        }
        else if(tight==0){
            for(int i=0;i<digits.size();i++){
                int n=stoi(digits[i]);
                if(n!=0){
                         res+=(solve(pos+1,0,zeros,digits,s));
                }
            
                
            }
        }
        return dp[pos][tight][zeros]=res;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        //tight 2 pos 10 
        memset(dp,-1,sizeof(dp));
        digits.insert(digits.begin(), "0");
        
        return solve(0,1,0,digits,s);
    }
};