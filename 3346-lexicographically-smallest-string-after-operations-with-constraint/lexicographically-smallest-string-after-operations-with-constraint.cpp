class Solution {
public:
    int distance(char ch1,char ch2){
        vector<char>temp={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        vector<char>temp2={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        if(ch1==ch2)return 0;
        for(int i=0;i<temp2.size();i++){
            temp.push_back(temp2[i]);
        }
        vector<int>dx;
        vector<int>dy;
        for(int i=0;i<temp.size();i++){
            if(ch1==temp[i]){
                dx.push_back(i);
            }
            else if(ch2==temp[i]){
                dy.push_back(i);
            }
            
        }
        return min(abs(dx[0]-dy[0]),abs(dx[0]-dy[1]));
    }
    string getSmallestString(string s, int k) {
       vector<char>temp={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        string ans="";
        int val=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<temp.size();j++){
                if(val+distance(s[i],temp[j])<=k) {
                    ans+=temp[j];
                    val+=distance(s[i],temp[j]);
                    break;
                }
            }
            
        }
        return ans;
    }
};