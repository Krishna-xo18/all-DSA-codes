class Solution {
public:
       bool ispossible(vector<int>v,int val)
        {
            int pos=0;

            for(int i=0;i<v.size();i++){
                if(v[i]-val+1>0){
                     pos+=(v[i]-val+1);
                }
               
                if(pos>=3){
                    return true;
                }
              //  cout<<pos<<endl;
            }
            if(pos>=3){
                return true;
            }
            return false;
        }
    int maximumLength(string s) {
        unordered_map<char,vector<int>>mp;
        char run=s[0];
        int count =1;
        int maxi=0;
        for(int i=1;i<s.size();i++){
            if(run==s[i]){
                count++;
                if(i==s.size()-1){
                     maxi=max(maxi,count);
                mp[run].push_back(count);
                }
            }
            else{
                
                maxi=max(maxi,count);
                mp[run].push_back(count);
                count=1;
                run=s[i];
                 if(i==s.size()-1){
                     maxi=max(maxi,count);
                mp[run].push_back(count);
                }
           }
        }
                
       
        int ans=-1;
               // cout<<ispossible({1,5},3);
        for(auto x:mp){
            vector<int>vec=x.second;
           // cout<<x.first<<endl;
            
           
            int start=0;
            int end=maxi;
            int mid=start+(end-start)/2;
            
            while(start<=end){
                if(ispossible(vec,mid)){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
                mid=start+(end-start)/2;
            }
            ans=max(ans,end);
        }
        if(ans==0){
            return -1;
        }
        return ans;
        }
       
        
};