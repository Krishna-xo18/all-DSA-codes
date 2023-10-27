class Solution {
public:
    
    #define ll long long
    ll int mod=1e9+7;
    ll int solve(int product,vector<int>&arr,unordered_map<int,int>&dp){

        ll int ans=1;
        if(dp.find(product)!=dp.end()){
            return dp[product];
        }
        for(int i=0;i<arr.size();i++){
            if(product%arr[i]==0){
                int num1=arr[i];
                int num2=product/arr[i];
            if(binary_search(arr.begin(),arr.end(),num2)){
                    ans=(ans+solve(num1,arr,dp)*solve(num2,arr,dp))%mod;
                }
            }
        }
        return dp[product]=(ans);
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int>dp;
        ll int ans=0;
        for(int i=0;i<arr.size();i++){
            ans=(ans+solve(arr[i],arr,dp))%mod;
        }
          return ans;
    }
};