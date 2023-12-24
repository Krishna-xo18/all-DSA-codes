class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        set<int>diff1;
        vector<int>diff2;
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        hFences.push_back(m);
         vFences.push_back(n);
        hFences.insert(hFences.begin(),1);
         vFences.insert(vFences.begin(),1);
       
        for(int i=0;i<hFences.size();i++){
            
            for(int j=i+1;j<hFences.size();j++){
                diff1.insert(hFences[j]-hFences[i]);
            }
        }
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                diff2.push_back(vFences[j]-vFences[i]);
            }
        }
       
        sort(diff2.begin(),diff2.end());
   long long ans=-1;
    long long int mod=1e9+7;
for(int i=diff2.size()-1;i>=0;i--){
    if(diff1.find(diff2[i])!=diff1.end()){
        {
           ans=diff2[i] ;
            ans=ans%mod;
              long long x=(long long)((long long )ans*(long long )ans);
            return (x)%mod;
        }
    }
}
        
       
    
        
        return -1;
    }
};