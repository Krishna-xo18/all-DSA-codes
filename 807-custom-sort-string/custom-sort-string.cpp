class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        vector<int>temp(s.size(),0);
        for(int i=0;i<order.size();i++){
          for(int j=0;j<s.size();j++){
              if(s[j]==order[i]){
                  ans+=s[j];
                  temp[j]=1;
              }
          }
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i]==0){
                ans+=s[i];
            }
        }
        return ans;
    }
};