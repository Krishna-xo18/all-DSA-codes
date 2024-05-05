class Solution {
public:
    bool solve(string s,int len){
        vector<int>alpha(27,0);
        if(s.size()%len!=0)return false;
        for(int i=0;i<len;i++){
          
            alpha[s[i]-'a']++;
        }
        
       
        vector<int>v(27,0);
        for(int j=len;j<s.size();j++){
           
            v[s[j]-'a']++;
             if((j+1)%len==0){

                for(int i=0;i<v.size();i++){
                    if(v[i]!=alpha[i])return false;
                    v[i]=0;
              }
                    
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        
        set<char>f;
        for(int i=0;i<s.size();i++){
            f.insert(s[i]);
        }
        if(f.size()==1)return 1;
        vector<int>temp;
        for(int i=2;i<s.size();i++){
            if(s.size()%i==0)temp.push_back(i);
        }
        for(int i=0;i<temp.size();i++){
            if(solve(s,temp[i]))return temp[i];
        }
        
        
       int x=s.size();
        return x;
    }
};