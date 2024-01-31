typedef long long ll;

class Solution {
public:
    bool checkPerfectSquare(ll x) {
        
        if(ceil(double(sqrt(x))) == floor(double(sqrt(x)))) return true;
        else return false;
    }
    
    int maximumLength(vector<int>& nums) {
        
        unordered_map<int, int> map;
        
        for(auto x : nums) {
            map[x]++;
        }
        
        int subLen = 1;
        for(ll x : nums) {
            int tempLen = 1;
            
            // Edge case i.e. when the current element is 1. It can 
            // include as many odd number of 1 in its subset.
            if(x == 1) {
                if(map[x] != 1) subLen = max(subLen, map[x] - (map[x]%2 == 0));
                continue;
            }
            
            // First check whether the current no. itself is eligible to be a perfect square.
            while(checkPerfectSquare(x)) {

                // Then check the other condition for it predecessors

                ll sqrtX = sqrt(x);
                if(map.find(sqrtX) != map.end() && map[sqrtX] >=2) {
                    tempLen += 2;
                }
                else {
                    break;
                }

                // Reduce the peak
                x = sqrtX;
            }
            
            subLen = max(subLen, tempLen);
        }
        
        return subLen;
    }
};