class Solution {
int lcm(int a, int b) {
        return (a * b) / __gcd(a, b);
    }
public:
    int subarrayLCM(vector<int> &nums, int k) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            if (g == k) res++;
            for (int j = i + 1; j < n; j++) {
                g = lcm(g, nums[j]);
                if (g == k) res++;
                else if (g < k) continue;
                else break;
            }
        }
        return res;
    }
};