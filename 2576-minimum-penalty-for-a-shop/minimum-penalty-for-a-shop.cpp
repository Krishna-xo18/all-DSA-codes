class Solution {
public:
    vector<int>  prefix_vec(string &s){
     vector<int>temp;
     int penalty=0;
     for(int i=0;i<s.size();i++){
        
        temp.push_back(penalty);
        if(s[i]=='N'){
            penalty++;
        }
     }
     return temp;
    }
    vector<int> suffix_vec(string &s){
       vector<int>temp;
       int penalty=0;
       for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='Y'){
               penalty++;
           }
           temp.push_back(penalty);
          
       }
       reverse(temp.begin(),temp.end());
       return temp;
    }
    int bestClosingTime(string customers) {
        auto prefix=prefix_vec(customers);
        auto suffix=suffix_vec(customers);
        int ans=0;
        int min_penalty=INT_MAX;
        int check=0;
        for(auto x:customers){
            if(x=='N'){
                check++;
            }
        }
        
        for(int i=0;i<prefix.size();i++){
             int penalty=prefix[i]+suffix[i];
             if(min_penalty>penalty){
                 min_penalty=penalty;
                 ans=i;
             }
        }
        if(check<min_penalty){
            return customers.size();
        }
        return ans;
    }
};