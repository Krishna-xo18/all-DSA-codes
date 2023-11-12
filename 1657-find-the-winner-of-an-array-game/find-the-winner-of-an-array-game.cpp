class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int>dq;
        int count=0;
         dq.push_back(arr[0]);
         if(k>=arr.size()){
             return *max_element(arr.begin(),arr.end());
         }
         int ans=0;
        for(int i=1;i<arr.size();i++){
             if(arr[i]>dq.front()){
               dq.push_back(dq.front());
               dq.pop_front();
               dq.push_front(arr[i]);
               count=1;
             }
             else{
                      count++;
             }
            
             if(count>=k){
                ans= dq.front();
                return ans;
             }

        }
        {
               return *max_element(arr.begin(),arr.end());
        }

    }
};