class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto element:mp){
            pq.push(make_pair(element.second,element.first));
        }
        vector<int>ans;
        while(k!=0){
            int element=pq.top().second;
            ans.push_back(element);
            pq.pop();
            k--;
        }

        return ans;
    }
};