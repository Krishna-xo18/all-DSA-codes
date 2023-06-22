class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>uglynumbers(n);
        uglynumbers[0]=1;
        int power2=0;
        int power3=0;
        int power5=0;
        for(int i=1;i<n;i++){
            uglynumbers[i]=min(uglynumbers[power2]*2, min(uglynumbers[power3]*3,uglynumbers[power5]*5));
            if(uglynumbers[i]==uglynumbers[power2]*2){
                power2++;
            }
             if(uglynumbers[i]==uglynumbers[power3]*3){
                power3++;
            }
             if(uglynumbers[i]==uglynumbers[power5]*5){
                power5++;
            }
        }
        return uglynumbers[n-1];
    }
};