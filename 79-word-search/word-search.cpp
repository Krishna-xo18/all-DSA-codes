class Solution {
public:
    bool solve(int i,int j,int k,vector<vector<int>>vis,vector<vector<char>>&board,string word){
         if(k>=word.size()){
              return true;
         }
         vis[i][j]=1;

         vector<int>dx={-1,0,1,0};
         vector<int>dy={0,-1,0,1};
          int ans=0;
         for(int s=0;s<4;s++){
            int n_i=i+dx[s];
            int n_y=j+dy[s];
            if(n_i>-1 && n_i<board.size() && n_y>-1 && n_y<board[0].size() && !vis[n_i][n_y] && word[k]==board[n_i][n_y]){
             
             ans|=solve(n_i,n_y,k+1,vis,board,word);
            }
         }
         return (ans==1);
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        map<char,int>mp;
        vector<pair<int,int>>temp;
        for(int i=0;i<board.size();i++){
             for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    temp.push_back({i,j});
                }
                mp[board[i][j]]++;
             }
        }
        map<char,int>mp1;
        for(int i=0;i<word.size();i++){
                   mp1[word[i]]++;
                   if(mp.find(word[i])!=mp.end()){
                        if(mp1[word[i]]>mp[word[i]])return false;
                   }
                   else return false;
                 
        }

         for(int k=0;k<temp.size();k++){
             {
                int i=temp[k].first;
                int j=temp[k].second;
            
                         if(solve(i,j,1,vis,board,word))return true;
                
             
            }
         }
         return false;
    }
};