class Solution {
public:
     static bool cmp(int a, int b)
{

   return (to_string(a)+to_string(b)>to_string(b)+to_string(a));
}
    string largestNumber(vector<int>& nums) {
        if(nums.size()<2){
            return to_string(nums[0]);
        }
        sort(nums.begin(),nums.end(),cmp);
        string ans="";
        
        for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0')
            {
                return ans;
            }
        }
        return to_string(0);
    }
};