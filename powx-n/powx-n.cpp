class Solution {
public:
    double negpow(double x,int n){
         if(n==-1){
            return x;
        }
        double ans=double(x*negpow(x,n+1));
        return ans;
    }
    double pospow(double x,int n){
        if(n==0){
            return 1;
        }
         if(n==1){
            return x;
        }
        double ans=double(x*pospow(x,n-1));
        return ans;
    }
    double myPow(double x, int n) {
        if(n==INT_MAX){
          return pow(x,n);
        }
        if(n==INT_MIN){
           return pow(x,n);
        }
        if(n<0){
          double ans=negpow(x,n);
          return double(1/ans);
        }
        else{
            return pospow(x,n);
        }
    }
};