class Solution {
public:
vector<int> intToBinaryVector(int num) {
    vector<int> binary(32, 0); 

    for (int i = 0; i < 32; ++i) {
        binary[i] = (num >> i) & 1; 
    }

    return binary;
}
int binaryVectorToInt(const vector<int>& binary) {
    int num = 0;

    for (int i = 0; i < 32; ++i) {
        if (binary[i] == 1) {
            num |= (1LL << i); 
        }
    }

    return num;
}
    int number(int num){
        vector<int>rep=intToBinaryVector(num);

        vector<int>num1(32,0);
        vector<int>num2(32,0);

        bool flag=false;
        if(rep[0]==0)return -1;
        vector<int>ones;
        for(int i=0;i<rep.size();i++){
          if(!flag && rep[i]==1 && i==0){
             num1[0]=1;
             num2[0]=0;
          }
          else if(rep[i]==0){
            flag=true;
          }
          else if(!flag){
               num1[i]=1;
               num2[i]=0;
               ones.push_back(i);
          }
          else{
            num1[i]=rep[i];
            num2[i]=rep[i];
          }
        }
        if(ones.size()>=1){
             num1[ones.back()]=0;
             num2[ones.back()]=1;
        }
        return min(binaryVectorToInt(num1),binaryVectorToInt(num2));

    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=number(nums[i]);
        }
        return ans;
    }
};