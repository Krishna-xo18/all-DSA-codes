class Solution {
public:
   #define ll long long 
    long long sumDigitDifferences(vector<int>& nums) {
        
        map<int,map<int,int>>mp;
        int n=nums.size();
        //  ll int nos=(ll)(n*(n-1))/2 ;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            
            for(int i=0;i<s.size();i++){
                mp[i][s[i]-'0']++;
            }
        }
        ll int ans=0;
        for(auto x:mp){
            
            auto c=x.second;
            vector<int>temp;
            for(auto v:c){
                temp.push_back(v.second);
            }
            for(int i=0;i<temp.size();i++){
                for(int j=i+1;j<temp.size();j++){
                    ans+=(ll)(temp[i]*temp[j]);
                }
            }
        }
        return ans;

    }
};