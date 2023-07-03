class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        
        sort(begin(buses),end(buses));
        sort(begin(passengers),end(passengers));
        int bus = buses.size() , pass = passengers.size() , j=0 ,ans=0,prev=0;
        for(int i=0;i<bus;i++){
            int count=0;
            while(j< pass && passengers[j]<=buses[i] && count<capacity)
            {
                if(passengers[j]-prev > 1) ans = passengers[j]-1;
                prev=passengers[j] ;
                 j++ ;
                 count++;
            }
            if(count<capacity && buses[i]-prev>=1) ans=buses[i];
        }
        return ans;
    }
};