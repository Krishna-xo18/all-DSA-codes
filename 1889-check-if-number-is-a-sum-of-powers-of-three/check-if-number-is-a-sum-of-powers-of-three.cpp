class Solution {
public:
    int solve(int idx,int n,vector<int>&temp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(idx>=temp.size()){
            return 0;
         }
       int take=solve(idx+1,n-temp[idx],temp);
       int nottake=solve(idx+1,n,temp);
       return take|| nottake;
    }
    bool checkPowersOfThree(int n) {
        vector<int>vec;
        for(int i=0;i<=15;i++){
            vec.push_back(pow(3,i));
           // cout<<vec.back()<<" ";
        }
        if(solve(0,n,vec)){
            return 1;
        }
        return 0;
    }
};