class Solution {
public:
    int solve(int stair,int jump,int check,int k,unordered_map<string,int>&mp){
        if(stair>k+1){
            return 0;
        }
        string key=to_string(stair)+'-'+to_string(jump)+'-'+to_string(check);
        int ans=0;
        if(mp.find(key)!=mp.end())return mp[key];
        if(stair==k)ans++;
        
        
        if(check==0 ){
            ans+=solve(stair-1,jump,check+1,k,mp);
        }
        ans+=solve(stair+pow(2,jump),jump+1,0,k,mp);
        return mp[key]=ans;
    }
    int waysToReachStair(int k) {
          unordered_map<string,int>mp;
        return solve(1,0,0,k,mp);
    }
};