class Solution {
public:
      vector<char> reverser(vector<char>& s,int start,int end){
        if(start>=end){
            return s;
        }
        swap(s[start],s[end]);
        return reverser(s,start+1,end-1);

    }
    void reverseString(vector<char>& s) {
        int length=s.size()-1;
          reverser(s,0,length);
    }
};