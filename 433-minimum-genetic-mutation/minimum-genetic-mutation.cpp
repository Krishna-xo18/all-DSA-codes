class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string>s;
        for(int i=0;i<bank.size();i++){
              s.insert(bank[i]);
        }
        vector<char>temp={'A','C','G','T'};
        queue<pair<int,string>>q;
        q.push({0,startGene});
        while(!q.empty()){
            auto node=q.front();
            int mutation=node.first;
            string curr=node.second;
            q.pop();
            if(curr==endGene){
                return mutation;
            }
            for(int i=0;i<curr.size();i++){
                string original=curr;
                for(int k=0;k<4;k++){
                    curr[i]=temp[k];
                    if(s.find(curr)!=s.end()){
                        s.erase(curr);
                        q.push({mutation+1,curr});
                    }
                }
                curr=original;
            }
        }
        return -1;
    }
};