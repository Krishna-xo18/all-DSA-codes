class Solution {
public:
 vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else 
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i<m)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        
        nums1=ans;
        return nums1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>mergedarray=merge(nums1,nums2);
        double ans;
        if(mergedarray.size()%2==1){
            ans=mergedarray[mergedarray.size()/2];
        }
        else{
            int element1=mergedarray[mergedarray.size()/2];
            int element2=mergedarray[(mergedarray.size()/2)- 1];
             ans=double(double(element1+element2)/2);
        }
        return ans;
    }
};