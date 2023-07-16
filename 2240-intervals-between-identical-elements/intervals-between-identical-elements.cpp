class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<int>nums=arr;
        map<long long ,long long>total;
       map<long long,long long>freq;
       map<long long,long long>left_cnt;
       map<long long,long long>left_freq;
       for(int i=0;i<nums.size();i++){
           total[nums[i]]+=i;
           freq[nums[i]]++;
           left_cnt[nums[i]]++;
           left_cnt[nums[i]]--;
           left_freq[nums[i]]++;
           left_freq[nums[i]]--;
       }
      vector<long long >ans;
        for(int i=0;i<nums.size();i++){
          long long  int right_freq=(long long)(freq[nums[i]]-left_freq[nums[i]]-1);
           long long int right_cnt=(long long)(total[nums[i]]-left_cnt[nums[i]]-i);
            long long int x=(long long)(i*left_freq[nums[i]]);
            long long int y=(long long)(right_cnt-left_cnt[nums[i]]);
            long long int z=(long long)(i*(right_freq));
           long long int val=(long long)(x+y-z);
           left_cnt[nums[i]]+=i;
           left_freq[nums[i]]++;
           ans.push_back(val);
        }
        return ans;
    }
};