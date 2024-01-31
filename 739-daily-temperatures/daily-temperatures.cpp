class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        stack<int>s;
        ans.push_back(0);
        for(int i=temperatures.size()-1;i>0;i--){
             if(temperatures[i-1]<temperatures[i]){
                s.push(i);
                ans.push_back(1);
            }
            else if(temperatures[i-1]>=temperatures[i]){
                while(!s.empty()  && temperatures[i-1]>=temperatures[s.top()]  ){
                    s.pop();
                }
                if(!s.empty()){
                ans.push_back(s.top()-i+1);
                s.push(i-1);
                }
                if(s.empty()){
                    ans.push_back(0);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};