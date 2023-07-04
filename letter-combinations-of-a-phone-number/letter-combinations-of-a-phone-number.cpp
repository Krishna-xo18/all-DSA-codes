class Solution {
public:
     void helper(int len,vector<string>&ans,vector<string>&temp,int index,string s){
        if(index==len){
            ans.push_back(s);
            return ;
        }
        
        for(int i=0;i<temp[index].size();i++){
            s.push_back(temp[index][i]);
            helper(len,ans,temp,index+1,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int len=digits.size();
        vector<string>ans;
        if(len==0){
            return ans;
        }
        vector<string>v={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>temp;
        for(int i=0;i<len;i++){
            int alpha=digits[i]-'0';
            temp.push_back(v[alpha]);
        }
        
        string s;
        helper(len,ans,temp,0,s);
        return ans;
    }
};