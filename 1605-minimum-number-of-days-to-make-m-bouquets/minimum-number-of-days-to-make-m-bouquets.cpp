class Solution {
public:
    bool is_possible(int day,int m,int k,vector<int>&bloomDay){
        int flower_count=0;
        int alpha=0;
        for(int i=0;i<bloomDay.size();i++){
            
            if(bloomDay[i]<=day){
                flower_count++;
                if(k==flower_count){
                    alpha++;
                    flower_count=0;
                }
            }
            else{
                flower_count=0;
            }
        }
        if(alpha>=m){
             return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int mid=start-(end-start)/2;
        long long int z=(long long )((long long )m*(long long )k);
        if(z>bloomDay.size()){
            return -1;
        }
        while(start<=end){
            if(is_possible(mid,m,k,bloomDay)){
                end=mid-1;
            }
            else{
                 start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return start;
    }


};