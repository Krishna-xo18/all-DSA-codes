class Solution {
public:
     bool isVowel(char s){
         if(s=='a' ||s=='e' ||s=='i' ||s=='o' ||s=='u' ){
             return true;
         }
         return false;
     }
    int maxVowels(string s, int k) {
        deque<char>dq;
        int vowel_cnt=0;
        int ans=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                vowel_cnt++;
            }
            dq.push_back(s[i]);
        }
        ans=max(ans,vowel_cnt);
        for(int i=k;i<s.size();i++){
            if(isVowel(dq.front())){
                vowel_cnt--;
            }
            if(isVowel(s[i])){
                vowel_cnt++;
            }
            dq.pop_front();
            dq.push_back(s[i]);
            ans=max(ans,vowel_cnt);
        }
        return ans;
    }
};