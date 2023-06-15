class Solution {
public:

    
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp;
        temp=nums;
        sort(temp.begin(),temp.end());
        bool flag=false;
        int start=0;
        int end=0;
        if(temp.size()==1){
            return 0;
        }
        for(int i=0;i<temp.size();i++){
          if(nums[i]!=temp[i]){
              if(flag==false){
                  start=i;
              }
              flag=true;
             // start=min(start,i);
              end=max(end,i);
          }
        }
        if(start==0 && end==temp.size()-1){
            return temp.size();
        }
        if(!flag){
            return 0;
        }
        return end-start+1;

        

    }
};