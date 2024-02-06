class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        int j=0;
        map<char,int>mp_t;
        map<char,int>mp_s;
        
        for(int i=0;i<t.size();i++){
            mp_t[t[i]]++;
        }
        int len2=t.size();
        int len1=s.size();
        int count=0;
        if(len1<len2){
            return "";
        }
        int idx1=0;
        int idx2=0;
        int len=INT_MAX;
        while(j<s.size()){
              mp_s[s[j]]++;
           if(mp_t.find(s[j])!=mp_t.end()){
               if(mp_s[s[j]]<=mp_t[s[j]]){
                   count++;
               }
           }
        
           if(count==len2){
               while(mp_s[s[i]]>mp_t[s[i]] || mp_t[s[i]]==0 ){
                  {
                      mp_s[s[i]]--;
                  }
                 i++;
                   
               }
                if(len>j-i+1){
                 
                  len=j-i+1;
                  idx1=i;
                  
             }
           }
           
           j++;
        }
        if(len==INT_MAX){
            return "";
        }
        return s.substr(idx1,len);
    }
};