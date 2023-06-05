class Solution {
public:

    int nextbigthing(vector<int>&nums2,int index,int len2){
        int ans=-1;
        
        for(int i=index+1;i<len2;i++){
            if(nums2[index]<nums2[i]){
                ans=nums2[i];
                break;
            } 
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>finalans;
        int len1=nums1.size();
        int len2=nums2.size();
        for(int i=0;i<len1;i++ ){
            for(int j=0;j<len2;j++){
                if(nums1[i]==nums2[j]){
                    finalans.push_back(nextbigthing(nums2,j,len2));
                }
            }
        }
        return finalans;
    }
};