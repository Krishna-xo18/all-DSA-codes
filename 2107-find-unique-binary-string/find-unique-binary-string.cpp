class Solution {
public:
    vector<string>temp;
    void generate(string s,int len){
        if(s.size()==len){
            temp.push_back(s);
            return ;
        }
        s+='0';
        //backtrack
        generate(s,len);
        s.pop_back();
        s+='1';
        generate(s,len);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string s;
        generate(s,nums[0].size());
        for(int i=0;i<temp.size();i++){
            bool found=false;
            for(int j=0;j<nums.size();j++){
                if(temp[i]==nums[j]){
                    found=true;
                    break;
                }
            }
            if(!found){
                return temp[i];
            }
        }
        return "";
    }
};