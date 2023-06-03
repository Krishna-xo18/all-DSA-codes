class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<int>digits;
        stack<char>var;
        int i=0;
        string aws="";
        while(i!=s.size()){
           if(isdigit(s[i])){
               aws+=s[i];
           }
           else if(isalpha(s[i]) || s[i]=='['){
               var.push(s[i]);
               
           }
           else if (s[i]==']'){
                 string x="";
                 while(var.top()!='['){
                     x=x+var.top();
                     var.pop();
                 }
                 reverse(x.begin(),x.end());
                 var.pop();
                 for(int i=0;i<digits.top();i++){
                     int j=0;
                     while(j!=x.size()){
                         char alpha=x[j];
                         var.push(alpha); 
                         j++;
                         
                         
                     }
                 }
                 cout<<endl;
                 digits.pop();
           }
           if(i!=s.size()-1 && !isdigit(s[i+1]) && isdigit(s[i])){
                digits.push(stoi(aws));
                aws="";
           }
           i++;
        }
          while(!var.empty()){
            ans=ans+var.top();
            var.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};