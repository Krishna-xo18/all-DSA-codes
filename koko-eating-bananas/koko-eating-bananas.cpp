class Solution {
public:


    bool ispossible(int value,long long int hours,vector<int>& piles){
        long long int count=0;
         for(int i=0;i<piles.size();i++){
             if(piles[i]<=value){
                 count++;
             }
             else{
                count=count+ (long long) (piles[i]/value);
                if(piles[i]%value!=0){
                    count++;
                }
             }
         }
         if(count<=hours){
             return true;
         }
         return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int start=1;
        int end=piles[piles.size()-1];
        int mid=start+(end-start)/2;

        while(start<=end){
            if(!ispossible(mid,h,piles)){
               start=mid+1;
            }
            else{
                end=mid-1;
            }
             mid=start+(end-start)/2;
        }
        return start;
    }
};