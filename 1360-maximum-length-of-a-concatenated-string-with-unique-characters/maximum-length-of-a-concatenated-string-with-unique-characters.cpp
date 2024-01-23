class Solution {
public:
    int count(int n)
{
    if (n == 0)
        return 0;
    else
        return (n & 1) + count(n >> 1);
}

    int solve(int idx,int curr,vector<int>temp2,vector<int>size){
        if(idx>=temp2.size()){
          return 0;
        }
        int nottake=solve(idx+1,curr,temp2,size);
        int take=0;
        if((count(temp2[idx])+count(curr))==count(temp2[idx]^curr)){
            take=size[idx]+solve(idx+1,temp2[idx]^curr,temp2,size);
        }
        return max(take,nottake);
    }
    int maxLength(vector<string>& arr) {
        vector<string>temp;
        for(int i=0;i<arr.size();i++){
            sort(arr[i].begin(),arr[i].end());
            bool flag=true;
            for(int j=1;j<arr[i].size();j++){
               if(arr[i][j]==arr[i][j-1]){
                 flag=false;
               }
            }
            if(flag){
                temp.push_back(arr[i]);
            }
        }
 
        vector<int>temp2;
        vector<int>size;
        for(int i=0;i<temp.size();i++){
            int num=0;
            for(int j=0;j<temp[i].size();j++){
                char alpha=temp[i][j];
               
                num=num | 1 <<(alpha-'a');
            }
            size.push_back(temp[i].size());
            
            temp2.push_back(num);
        }
       return solve(0,0,temp2,size);
    }
};