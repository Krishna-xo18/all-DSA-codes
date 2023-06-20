class Solution {
public:
    vector< int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(long long int i=0;i<spells.size();i++){
          long long  int start=0;
          long long int end=potions.size()-1;
         long long  int mid=start+(end-start)/2;
           
           while(start<=end){
               long long int alpha=(long long int)potions[mid]*spells[i];
              if(alpha<success){
                  start=mid+1;
              }
              else if(alpha>=success){
                  end=mid-1;
              }
              
              mid=start+(end-start)/2;
           }
           ans.push_back(potions.size()-mid);
        }
        return ans;
    }
};