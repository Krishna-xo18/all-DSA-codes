class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int num=0;
        string s="";
        for(int i=31;i>=0;i--){
            int bit1= (left >> (i)) % 2;
            int bit2= (right >> (i)) % 2;
           // cout<<bit1<<" "<<bit2<<endl;
         if(bit1==bit2){
           if(bit1==0){
               s+='0';
           }
           else{
            s+='1';
           }
         }
         else{
             for(int j=i;j>=0;j--){
                 s+='0';
             }
             break;
         }
         
        }
         num=stoi(s,0,2);
       
        return num;
    }
};