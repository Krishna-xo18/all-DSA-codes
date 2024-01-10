class Solution {
public:
    #define ll long long
    int integerReplacement(int n) {
        queue<pair<ll int,ll int>>q;
        q.push({n,0});
        set<ll int>vis;
        while(!q.empty()){
            ll int num=q.front().first;
            ll int step=q.front().second;
            q.pop();
            vis.insert(num);
            if(num==1){
                return step;
            }
            if(num&1){
                if(vis.find(num+1)==vis.end()){

                    q.push({num+1,step+1});
                }
                if(vis.find(num-1)==vis.end()){
                    q.push({num-1,step+1});
                }
                
            }
            else{
                  if(vis.find(num/2)==vis.end()){
                    q.push({num/2,step+1});
                }
            }
        }
        return -1;
    }
};