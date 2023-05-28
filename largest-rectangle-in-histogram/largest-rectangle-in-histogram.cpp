class Solution {
public:

   vector<int> nextsmallerelement(vector<int>& heights,int x){

       stack<int>s;
       s.push(-1);
        vector<int>ans(x);

       for(int i=x-1;i>=0;i--){
          int curr=heights[i];
          while(s.top()!=-1 && heights[s.top()]>=curr){
              s.pop();
          }
          ans[i]=s.top();
          s.push(i);
       }
       return ans;
   }
   vector<int> prevsmallerelement(vector<int>& heights,int x){

       stack<int>s;
       s.push(-1);
        vector<int>ans(x);

       for(int i=0;i<x;i++){
          int curr=heights[i];
          while(s.top()!=-1 && heights[s.top()]>=curr){
              s.pop();
          }
          ans[i]=s.top();
          s.push(i);
       }
       return ans;
   }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        next=nextsmallerelement(heights,n);
        vector<int>prev(n);
        prev=prevsmallerelement(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newarea=l*b;
            area=max(area,newarea);
        }
        return area;
    }
};