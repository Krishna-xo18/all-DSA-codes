class Solution {
public:
    int dp[5][1005][2005];
    int mod = 1e9 + 7;
    int f(int ind, string &s, int prev, int score) {
        if (ind == s.size()) {
            if (score > 0)return 1;
            return 0;
        }
        if (dp[prev][ind][score + 1002] != -1) {
            return dp[prev][ind][score + 1002];
        }
        if (prev == 4) {
            if (s[ind] == 'F') {
                int x = f(ind + 1, s, 1, score) % mod;
                int y = f(ind + 1, s, 2, score + 1) % mod;
                int z = f(ind + 1, s, 3, score - 1) % mod;
                return dp[prev][ind][score+ 1002]=((x + y) % mod + z) % mod;
            }
            else if (s[ind] == 'W') {
                int x = f(ind + 1, s, 1, score - 1) % mod;
                int y = f(ind + 1, s, 2, score) % mod;
                int z = f(ind + 1, s, 3, score + 1) % mod;
                return dp[prev][ind][score+ 1002]=((x + y) % mod + z) % mod;
            }
            else {
                int x = f(ind + 1, s, 1, score + 1) % mod;
                int y = f(ind + 1, s, 2, score - 1) % mod;
                int z = f(ind + 1, s, 3, score) % mod;
                return dp[prev][ind][score+ 1002]=((x + y) % mod + z) % mod;
            }
        }
        else {
            if (prev == 1) {
                if (s[ind] == 'F') {
                    int y = f(ind + 1, s, 2, score + 1) % mod;
                    int z = f(ind + 1, s, 3, score - 1) % mod;
                    return dp[prev][ind][score+ 1002]=(y + z) % mod;
                }
                else if (s[ind] == 'W') {
                    int y = f(ind + 1, s, 2, score) % mod;
                    int z = f(ind + 1, s, 3, score + 1) % mod;
                    return dp[prev][ind][score+ 1002]=(y + z) % mod;
                }
                else {
                    int y = f(ind + 1, s, 2, score - 1) % mod;
                    int z = f(ind + 1, s, 3, score) % mod;
                    return dp[prev][ind][score+ 1002]=(y + z) % mod;
                }
            }
            else if (prev == 2) {
                if (s[ind] == 'F') {
                    int x = f(ind + 1, s, 1, score) % mod;
                    int z = f(ind + 1, s, 3, score - 1) % mod;
                    return dp[prev][ind][score+ 1002]=(x + z) % mod;
                }
                else if (s[ind] == 'W') {
                    int x = f(ind + 1, s, 1, score - 1) % mod;
                    int z = f(ind + 1, s, 3, score + 1) % mod;
                    return dp[prev][ind][score+ 1002]=(x + z) % mod;
                }
                else {
                    int x = f(ind + 1, s, 1, score + 1) % mod;
                    int z = f(ind + 1, s, 3, score) % mod;
                    return dp[prev][ind][score+ 1002]=(x + z) % mod;
                }
            }
            else {
                if (s[ind] == 'F') {
                    int x = f(ind + 1, s, 1, score) % mod;
                    int y = f(ind + 1, s, 2, score + 1) % mod;
                    return dp[prev][ind][score+ 1002]=(x + y) % mod;
                }
                else if (s[ind] == 'W') {
                    int x = f(ind + 1, s, 1, score - 1) % mod;
                    int y = f(ind + 1, s, 2, score) % mod;
                    return dp[prev][ind][score+ 1002]=(x + y) % mod;
                }
                else {
                    int x = f(ind + 1, s, 1, score + 1) % mod;
                    int y = f(ind + 1, s, 2, score - 1) % mod;
                    return dp[prev][ind][score+ 1002]=(x + y) % mod;
                }
                
            }
        }
    }

    int countWinningSequences(string s) {
        memset(dp, -1, sizeof(dp));
        return f(0, s, 4, 0) % mod;
    }
};