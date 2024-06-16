class Solution {
public:
    #define ll long long
    // ll int dp[10100];


ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

long long maximumTotalDamage(vector<int>& power) {
    map<int, int> mp;
    
   
    for (int i = 0; i < power.size(); i++) {
        mp[power[i]]++;
    }
    
    vector<pair<int, int>> temp;
    vector<int> check;
    
    
    for (const auto& x : mp) {
        temp.push_back({x.first, x.second});
        check.push_back(x.first);
    }
    
    int n = check.size();
    vector<ll> dp(n + 1, 0); 
    for (int idx = n - 1; idx >= 0; idx--) {
        ll nottake = dp[idx + 1];
        int i = lower_bound(check.begin(), check.end(), check[idx] + 3) - check.begin();
        ll take = (ll)temp[idx].first * (ll)temp[idx].second + (i < n ? dp[i] : 0);
        dp[idx] = max(take, nottake);
    }
    
    return dp[0];
}
};