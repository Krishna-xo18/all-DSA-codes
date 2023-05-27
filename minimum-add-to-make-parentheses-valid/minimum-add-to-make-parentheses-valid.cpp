class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==0){
            return 0;
        }
        stack<char>s1;
        for(int i=0;i<s.size();i++){
            if(s1.empty()){
                s1.push(s[i]);
            }
            else if(s[i]=='('){
               s1.push(s[i]);
            }
            
            else if(s[i]==')' && s1.top()=='('){
                s1.pop();
            }
            else{
                s1.push(')');
            }
        }
        return s1.size();
    }
};