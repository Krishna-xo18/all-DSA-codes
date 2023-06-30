class Solution {
public:
  vector<string>ans;
    void helper(int n,string &s,int open,int close){
        if(open==close and open==n-1){
          ans.push_back(s);
          return ;
        }
        if(open<n){
        s.push_back('(');
        helper(n,s,open+1,close);
        s.pop_back();
        }
        if(open>close){
        s.push_back(')');
        helper(n,s,open,close+1);
        s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        helper(n+1,s,0,0);
        return ans;
    }
};