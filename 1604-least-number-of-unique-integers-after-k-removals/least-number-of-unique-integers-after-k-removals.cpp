class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>temp;
        for(auto x: mp){
            temp.push_back(x.second);
          //  cout<<x.second<<" ";
        }
        sort(temp.begin(),temp.end());
        int i=0;
        while(k>0){
            k-=temp[i];
            if(k>=0){
             i++;
            }
        }
        return temp.size()-i;
    }
};