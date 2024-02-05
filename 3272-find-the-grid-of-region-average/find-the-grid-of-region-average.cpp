class Solution {
public:
    
    vector<int> dx = {0, +1, 0, -1};
    vector<int> dy = {+1, 0, -1, 0};
    
    bool check(int i,  int j, int rangeX, int rangeY, vector<vector<int>>& image, int t){
        for(int k=0; k<4; k++){
            int newX = i+dx[k], newY = j+dy[k];
            if(newX>=0 && newY>=0 && newX<image.size() && newY<image[0].size() && newX<=rangeX && newY<=rangeY && newX>=rangeX-2 && newY>=rangeY-2){
                if(abs(image[i][j]-image[newX][newY])>t) return false;
            }
        }
        
        return true;
    }
    
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size(), m = image[0].size();
        
        vector<vector<vector<int>>> average(n, vector<vector<int>>(m, vector<int>()));
        
        for(int i=2; i<n; i++){
            for(int j=2; j<m; j++){
                
                bool isRegion = true;
                int sum = 0;
                
                for(int x=i-2; x<=i; x++){
                    for(int y=j-2; y<=j; y++){
                        sum += image[x][y];
                        if(!check(x, y, i, j, image, threshold)){
                            isRegion = false;
                            break;
                        }
                    }
                    if(!isRegion) break;
                }
                
                if(isRegion){
                    int avg = sum/9;
                    
                    for(int x=i-2; x<=i; x++){
                        for(int y=j-2; y<=j; y++){
                            average[x][y].push_back(avg);
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<int>& v = average[i][j];
                if((int)v.size() == 0) ans[i][j] = image[i][j];
                else{
                    int sum = 0;
                    int count = v.size();
                    
                    for(int val: v) sum += val;
                    ans[i][j] = sum/count; 
                }
            }
        }
        
    
        
        return ans;
    }
};