class Solution {
public:
bool prime(int n)
{
    // Check if n=1 or n=0
    if (n <= 1)
        return 0;
    // Check if n=2 or n=3
    if (n == 2 || n == 3)
        return 1;
    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
 
    return 1;
}
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>s;
        for(int i=2;i<=n/2;i++){
            vector<int>x;
            if(prime(i) ){
                if(prime(n-i) && n-i!=1){
                    x.push_back(min(i,n-i));
                    x.push_back(max(i,n-i));
                    s.push_back(x);
                }
            }
        }
    
        return s;
    }
};