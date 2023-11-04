class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        for(int i=0;i<right.size();i++){
          left.push_back(n-right[i]);
        }
        int ans=*max_element(left.begin(),left.end());

       return ans;
    }
};