class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int attempt=minutesToTest/minutesToDie;
        int ans=0;
        while(pow(attempt+1,ans)<buckets){
            ans++;
        }
        return ans;
    }
};