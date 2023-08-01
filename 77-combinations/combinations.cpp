class Solution {
public:
  vector<vector<int>>ans;
  void solve(int idx,int k,vector<int>&temp,vector<int>&temp2){
     if(temp.size()==k){
       ans.push_back(temp);
       return;
     }
     if(idx==temp2.size()){
         return;
     }
     temp.push_back(temp2[idx]);
     solve(idx+1,k,temp,temp2);
     temp.pop_back();
     solve(idx+1,k,temp,temp2);

  }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp2;
        for(int i=1;i<=n;i++){
            temp2.push_back(i);
        }
        vector<int>temp;
        solve(0,k,temp,temp2);
        return ans;
    }
};