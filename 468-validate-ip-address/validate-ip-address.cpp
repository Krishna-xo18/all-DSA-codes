class Solution {
public:
    bool check1(string s){
        if(s.size()==0 || s.size()>4){
            return false;
        }
        for(int i=0;i<s.size();i++){
            {
                
            if(s[i]>=97 && s[i]<=102) continue;
            else if(s[i]>=65 && s[i]<=70) continue;
            else if(s[i]>=48 && s[i]<58) continue;
                else{
                     return false;
                }
            }
        }
        return true;
    }
    bool IP6(string query){
       string s="";
       int dot_cnt=0;
       for(int i=0;i<query.size();i++){
           if(query[i]==':'){
               if(!check1(s)){
                   return false;
               }
               dot_cnt++;
               s="";
           }
           if(query[i]!=':'){
               s+=query[i];
           }
       }
       if(!check1(s)){
                   return false;
               }
               if(dot_cnt!=7){
               return false;
           }
       
       return true;
    }
    bool check2(string s){
        if(s.size()==0){
            return false;
        }
        if(s.size()!=1){
            if(s[0]=='0'){
                return false;
            }
        }
        for(int i=0;i<s.size();i++){
            if(!isdigit(s[i])){
                return false;
            }
        }
        if(s.size()>=4){
            return false;
        }
        int value=stoi(s);
        if(value<0 || value>255){
            return false;
        }
        return true;
    }
    bool IP4(string query){
            string s="";
           int  dot_cnt=0;
       for(int i=0;i<query.size();i++){
           if(query[i]=='.'){
               if(!check2(s)){
                   return false;
               }
               s="";
               dot_cnt++;
           }
           if(query[i]!='.'){
               s+=query[i];
           }
          
           
       }
        if(dot_cnt!=3){
               return false;
           }
        if(!check2(s)){
                   return false;
         }

       return true;
    }
    string validIPAddress(string queryIP) {
        string s1="IPv4";
         string s2="IPv6";
          string s3="Neither";
      for(int i=0;i<queryIP.size();i++){
          if(queryIP[i]=='.'){
              if(IP4(queryIP)){
                  return s1;
              }
              return s3;
          }
          if(queryIP[i]==':'){
              if(IP6(queryIP)){
                  return s2;
              }
              return s3;
          }
      }
      return s3;

    }
};