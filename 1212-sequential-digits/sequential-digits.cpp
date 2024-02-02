class Solution {
public:
    void solve(int k,string s,vector<int>&temp){
        string str="";
        for(int i=0;i<=s.size()-k;i++){
            string str="";
            for(int j=i;j<i+k;j++){
              str+=s[j];
            }
            temp.push_back(stoi(str));
        }
        
    }
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int>temp;
        for(int i=1;i<=9;i++){
            solve(i,s,temp);
        }
        vector<int>ans;
        for(int i=0;i<temp.size();i++){
            if(temp[i]>=low && temp[i]<=high){
              ans.push_back(temp[i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};