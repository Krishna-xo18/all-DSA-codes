class Solution {
public:
     #define ll long long
   
    long long distributeCandies(int n, int limit) {
        ll ans=0;
        for(int x=0;x<=min(n,limit);x++){
            ll rem=n-x;
            if(rem<=limit){
                ans+=(rem+1);
            }
            else if(rem<=2*limit)
            {
                ans+=(2*limit-rem+1);
            }
            else{
                ans+=0;
            }
        }
        return ans;
    }
};