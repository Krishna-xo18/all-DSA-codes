class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            vector<int>temp(27,0);
            for(int j=0;j<strs[i].size();j++){

                temp[strs[i][j]-'a']++;
            }

            mp[temp].push_back(strs[i]);
        }
         vector<vector<string>>ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;

    }
};