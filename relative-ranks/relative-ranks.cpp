class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<score.size();i++){
            pq.push(make_pair(score[i],i));
        }
        vector<string>ans(score.size(),"");
        int count=1;
        while(!pq.empty()){
            int element=pq.top().second;
            if(count==1){
                 ans[element]="Gold Medal";
            }
            else if(count==2){
                ans[element]="Silver Medal";
            }
            else if(count==3){
                ans[element]="Bronze Medal";
            }
            else{
            ans[element]=to_string(count);
            }
            count++;
            pq.pop();
        }
        return ans;
        
    }
};