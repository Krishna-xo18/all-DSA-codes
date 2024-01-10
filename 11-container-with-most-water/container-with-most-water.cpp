class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=INT_MIN;
        while(i<j){
          if(height[i]>height[j]){
              ans=max(ans,height[j]*(j-i));
              j--;
              
          }
          else{
                 ans=max(ans,height[i]*(j-i));
              i++;
           
          }
        }
        return ans;
    }
};