class Solution {
public:
    int arrangeCoins(int n) {
       
       int start=0;
       int end=n-1;
       int mid=start+(end-start)/2;
       if(n==1){
           return 1;
       }
       while(start<=end){
           long long int val=(long long) mid*(mid+1)/2;
           long long int checker=n;
           if(val<=checker){
               start=mid+1;
           }
           else{
               end=mid-1;
           }
           mid=start+(end-start)/2;
       }
       return end;

    }
};