class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int idx=0;
        bool flag=false;
        for(int i=1;i<s.size();i++){
          int num1=s[i]-'0';
          int num2=s[i-1]-'0';
          if(num1>num2){
              idx=i;
          }
          if(num1<num2){
              flag=true;
              break;
          }
        }
        if(flag){
            int num=s[idx]-'0';
            s[idx]=(num-1)+'0';
            for(int i=idx+1;i<s.size();i++){
                s[i]='9';
            }
            n=stoi(s);
        }
        return n;

    }
};