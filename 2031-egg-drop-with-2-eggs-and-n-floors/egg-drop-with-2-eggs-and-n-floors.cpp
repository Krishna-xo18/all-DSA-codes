class Solution {
public:
    bool is_possible(int x,int n){
        int val=0;
        while(x!=0){
            val+=x;
            x--;
        }
        if(val>=n ){
            return true;
        }
        return false;
    }
    int twoEggDrop(int n) {
        int start=1; 
        int end=n;
        int mid=end+(start-end)/2;
        while(start<=end){
            if(is_possible(mid,n)){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=end+(start-end)/2;
        }
        return start;

    }
};