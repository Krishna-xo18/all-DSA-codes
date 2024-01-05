class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>temp;
        for(int i=0;i<bank.size();i++){
            int cnt=0;
            for(int j=0;j<bank[i].size();j++){
                  if(bank[i][j]=='1'){
                      cnt++;
                  }
            }
            temp.push_back(cnt);
        }
      vector<int>temp1;
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=0){
                temp1.push_back(temp[i]);
            }
        }
        int ans=0;
        for(int i=1;i<temp1.size();i++){
            ans+=(temp1[i]*temp1[i-1]);
        }
        return ans;
    }
};