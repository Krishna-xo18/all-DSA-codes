class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>mp1;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
        }
        unordered_map<char,int>mp2;
        for(int i=0;i<word2.size();i++){
            mp2[word2[i]]++;
        }

        vector<int>temp1;
        vector<int>temp2;
        vector<char>temp3;
        vector<char>temp4;
        for(auto x: mp1){
            temp1.push_back(x.second);
            temp3.push_back(x.first);
        }
         for(auto x: mp2){
            temp2.push_back(x.second);
            temp4.push_back(x.first);
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
          sort(temp3.begin(),temp3.end());
            sort(temp4.begin(),temp4.end());
        if(temp1.size()!=temp2.size()){
            return false;
        }
         if(temp3.size()!=temp4.size()){
            return false;
        }
         for(int i=0;i<temp4.size();i++){
            if(temp3[i]!=temp4[i]){
                return false;
            }
        }
        for(int i=0;i<temp1.size();i++){
            if(temp1[i]!=temp2[i]){
                return false;
            }
        }
        return true;
    }
};