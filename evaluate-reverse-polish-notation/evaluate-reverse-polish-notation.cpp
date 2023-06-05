class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>digits;
        stack<char>operations;

        for(int i=0;i<tokens.size();i++){

            if(tokens[i]!="*" && tokens[i]!="+" &&   tokens[i]!="-" && tokens[i]!="/" ){
                int alpha=stoi(tokens[i]);
                digits.push(alpha);
               // cout<<alpha<<endl;
            }
            else if(tokens[i]=="*"){
                int digit1=digits.top();
                digits.pop();
                int digit2=digits.top();
                digits.pop();
                digits.push(digit1*digit2);
            }
             else if(tokens[i]=="+"){
                int digit1=digits.top();
                digits.pop();
                int digit2=digits.top();
                digits.pop();
                digits.push(digit1+digit2);
                // cout<<digit1<<digit2<<endl;
            }
             else if(tokens[i]=="-"){
                int digit1=digits.top();
                digits.pop();
                int digit2=digits.top();
                digits.pop();
                digits.push(digit2-digit1);
            }
            else if(tokens[i]=="/"){
                int digit1=digits.top();
                digits.pop();
                int digit2=digits.top();
                digits.pop();
                digits.push(digit2/digit1);
               // cout<<digit1<<digit2<<endl;
            }
        }
        return digits.top();
    }
};