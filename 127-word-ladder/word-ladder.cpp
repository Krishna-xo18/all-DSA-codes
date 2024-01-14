class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        queue<pair<int,string>>q;
        q.push({0,beginWord});
        s.erase(beginWord);
        while(!q.empty()){
            auto node=q.front();
            string currword=node.second;
            int steps=node.first;
            q.pop();
            if(currword==endWord){
                return steps+1;
            }
            for(int i=0;i<currword.size();i++){
                string original =currword;
                for(int j=0;j<26;j++){
                    currword[i]='a'+j;
                    if(s.find(currword)!=s.end()){
                        s.erase(currword);
                        q.push({steps+1,currword});
                    }
                }
                currword=original;
            }
        }
        
        return 0;
    }
};