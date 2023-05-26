class Solution {
public:
    bool isValid(string s) {

        stack<char>s1;
         
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' ){
               s1.push(s[i]);
            }
           else  if(s1.empty()){
                s1.push(s[i]);
            }
            else  if(s[i]=='}'){

                 if(s1.top()=='{'){
                 s1.pop();
                 }
                 else{
                     s1.push('}');
                 }

             }
             else  if(s[i]==')' ){
                 
                  if(s1.top()=='('){
                 s1.pop();
                 }
                 else{
                     s1.push(')');
                 }
             }
             else  if(s[i]==']' ){
                 if(s1.top()=='['){
                 s1.pop();
                 }
                 else{
                     s1.push(']');
                 }
                 
             }
        }
        if(s1.empty()){
            return true;
        }
        return false;
    }
};