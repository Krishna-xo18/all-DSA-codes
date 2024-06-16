class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        map<int,int>mp;
        long long ans=0;
        sort(hours.begin(),hours.end());
        for(int i=0;i<hours.size();i++){
            hours[i]=hours[i]%24;
        }
        for(int i=0;i<hours.size();i++){
            if(hours[i]==0){
                ans+=mp[0];
            }
            if(mp.find(24-hours[i])!=mp.end()){
                ans+=mp[24-hours[i]];
            }
            
            mp[hours[i]]++;
        }
        return ans;
        
        
    }
};