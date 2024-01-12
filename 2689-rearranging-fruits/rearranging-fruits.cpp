class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        unordered_map<int,int>mp;
        int mini=INT_MAX;
        for(int i=0;i<basket1.size();i++){
          mp[basket1[i]]++;
          mp1[basket1[i]]++;
          mini=min(mini,basket1[i]);
        }
        for(int i=0;i<basket2.size();i++){
           mp[basket2[i]]++;
           mp2[basket2[i]]++;
           mini=min(mini,basket2[i]);
        }
        vector<int>temp1;
        vector<int>temp2;
       
        for(auto x: mp){
          int val=x.first;
          int occur=x.second;
          int now1=0;
          int now2=0;
          if(mp1.find(val)!=mp1.end()){
            now1=mp1[val];
          }
         if(mp2.find(val)!=mp2.end()){
            now2=mp2[val];
          }
          if(occur%2==1){
              return -1;
          }

         // cout<<val<<" "<<" occurence "<<occur/2<<" "<< now1<<" "<<now2<<endl;
          if(now1<occur/2){
              for(int i=now1;i<occur/2;i++){
                  temp1.push_back(val);
              }
          }
          
          else if(now2<occur/2){
              for(int i=now2;i<occur/2;i++){
                  temp2.push_back(val);
              }
          }
        }
    
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        reverse(temp1.begin(),temp1.end());
        int x=temp1.size();
        long long ans=0;
        for(int i=0;i<temp1.size();i++){
             // indirect swapping
             int y=2*mini;
              //direct swapping
             int z=min(temp1[i],temp2[i]);
            ans+=(min(y,z));
        }
        return ans;
  
    }
};