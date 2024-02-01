class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>stk;
        stk.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
           if(stk.empty()){
               stk.push(asteroids[i]);
           }
           else if(asteroids[i]<0){
               while(!stk.empty()&& stk.top()>0 && asteroids[i]<0 && abs(stk.top())<abs(asteroids[i])){
                   stk.pop();
               }
               if(!stk.empty() && stk.top()>0 && asteroids[i]<0 && abs(stk.top())==abs(asteroids[i])){
                    stk.pop();
               }
               else if(stk.empty() || stk.top()*asteroids[i] > 0){
                   stk.push(asteroids[i]);
               }
               
           }
           else if(asteroids[i]>0){
               stk.push(asteroids[i]);
           }
        }
          vector<int>ans;
     while(!stk.empty()){
         ans.push_back(stk.top());
         stk.pop();
     }
     reverse(ans.begin(),ans.end());
     return ans;
    }
};