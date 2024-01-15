class Solution {
public:
    void solve(int idx,string s,vector<int>&temp,int &num,int count){
     if(count>=2){
         return ;
     }
      if(idx>=s.size()){ 
          return;
      }
       int alpha=stoi(s);
       num=max(num,alpha);
        for(int i=idx+1;i<s.size();i++){
            if(!temp[idx] && !temp[i]){
                swap(s[idx],s[i]);
                temp[idx]=1;
                temp[i]=1;

                solve(idx+1,s,temp,num,count+1);
                swap(s[idx],s[i]);
                temp[idx]=0;
                temp[i]=0;
                
            }
            solve(idx+1,s,temp,num,count);
           
        }
    }
    int maximumSwap(int num) {
        string s=to_string(num);
        vector<int>temp(s.size(),0);
        int ans=num;
        solve(0,s,temp,ans,0);
        return ans;
    }
};