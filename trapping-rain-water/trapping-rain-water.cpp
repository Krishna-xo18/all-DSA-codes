class Solution {
public:


    vector<int>prefixmax(vector<int>& height){

        vector<int>v;
        stack<int>s;
        s.push(height[0]);
        v.push_back(height[0]);
        for(int i=1;i<height.size();i++){
            if(height[i]>s.top()){
                s.push(height[i]);
            }
            v.push_back(s.top());
        }
       

        return v;
    }
    vector<int>suffixmax(vector<int>& height){

        vector<int>v;
        stack<int>s;
        s.push(height[height.size()-1]);
        v.push_back(height[height.size()-1]);
        for(int i=height.size()-2;i>=0;i--){
            if(height[i]>s.top()){
                s.push(height[i]);
            }
            v.push_back(s.top());
        }
       reverse(v.begin(),v.end());
        return v;
    }
    
    int trap(vector<int>& height) {
        vector<int>prefix=prefixmax(height);
        vector<int>suffix=suffixmax(height);
        int water=0;
        for(int i=0;i<height.size();i++){
            int rainwater=min(prefix[i],suffix[i])-height[i];
            if(rainwater>0){
                water+=rainwater;
            }
        }
        return water;
    }
};