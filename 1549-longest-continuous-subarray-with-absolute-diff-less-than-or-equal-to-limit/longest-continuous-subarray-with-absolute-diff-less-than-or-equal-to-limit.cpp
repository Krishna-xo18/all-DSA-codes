class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        set<int>s;
        map<int,int>mp;

        int i=0;
        int j=0;
       int len=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            s.insert(nums[j]);
            auto start=mp.begin();
            auto end=mp.rbegin();

            int mini=start->first;
            int maxi=end->first;
            while(abs(maxi-mini)>limit){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                    s.erase(nums[i]);
                }
                 auto start=mp.begin();
            auto end=mp.rbegin();

              mini=start->first;
               maxi=end->first;
                i++;
            }
            if(abs(maxi-mini)<=limit){
                len=max(len,j-i+1);
            }
            j++;
        }
        return len;
    }
};