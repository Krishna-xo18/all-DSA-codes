class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>temp(ratings.size(),1);
     
        for(int i=1;i<ratings.size();i++){
        if(ratings[i]>ratings[i-1]  ){
            temp[i]=temp[i-1]+1;
        }
        
        }
        for(int i=ratings.size()-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]  ){
            temp[i]=max(temp[i],temp[i+1]+1);
        }
      
        
        }
        
        int ans=0;
        for(int i=0;i<temp.size();i++)
        {
          //  cout<<temp[i]<<" ";
            ans+=temp[i];
        }
        return ans;
    }
};