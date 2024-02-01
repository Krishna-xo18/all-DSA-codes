class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(ans[ans.size()-1][1]>=start){
                ans[ans.size()-1][1]=max(end,ans[ans.size()-1][1]);
            }
            else{
                ans.push_back({start,end});
            }
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       intervals.push_back(newInterval);
       return merge(intervals); 
    }
};