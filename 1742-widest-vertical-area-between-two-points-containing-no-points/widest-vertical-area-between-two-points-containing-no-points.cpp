class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int>x_axis;
        for(int i=0;i<points.size();i++){
            x_axis.insert(points[i][0]);
        }
        vector<int>temp;
        for(auto x:x_axis){
            temp.push_back(x);
        }
        int ans=0;
        for(int i=1;i<temp.size();i++){
           ans=max(ans,temp[i]-temp[i-1]);
        }
        return ans;
    }
};