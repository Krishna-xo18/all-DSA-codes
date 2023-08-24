class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        map<char,int>mp;
        int max_freq=0;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            max_freq=max(max_freq,mp[s[j]]);
            while(((j-i+1)-max_freq)>k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return characterReplacement(answerKey,k);
    }
};