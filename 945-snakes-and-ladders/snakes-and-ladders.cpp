class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int>temp;
        temp.push_back(0);
        int n=board.size();
        for(int i=board.size()-1;i>=0;i--){
            if(i%2==(board.size()-1)%2){
            for(int j=0;j<board[i].size();j++){
                temp.push_back(board[i][j]);
            }
            }
            else{
                 for(int j=board[i].size()-1;j>=0;j--){
                temp.push_back(board[i][j]);
            }
            }
        }
     
        vector<int>vis(temp.size()+1,0);
        vector<int>dis(temp.size()+1,1e9);
        queue<pair<int,int>>q;
        {
            q.push({0,1});
        }
        dis[1]=0;
        while(!q.empty()){
            auto node=q.front();
            int steps=node.first;
            int square=node.second;
            q.pop();
           
            if(square==n*n){
                return steps;
            }
           for(int i=square+1;i<=min(square+6,n*n);i++){
                {
                   if(temp[i]!=-1 ){
                       if(dis[temp[i]]>steps+1){
                           dis[temp[i]]=steps+1;
                           q.push({dis[temp[i]],temp[i]});
                       }
                   }
                   else if(dis[i]>steps+1){
                       dis[i]=steps+1;
                       q.push({dis[i],i});
                   }
               }
           }
        }
        if(dis[n*n]==1e9)  return -1;
        else return dis[n*n];

    }
};