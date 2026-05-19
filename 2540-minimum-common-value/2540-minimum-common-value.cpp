class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        long long int n = nums1.size();
        long long int m = nums2.size();
        for(int i=0,j=0; i<n && j<m;)
        {
            if(nums1[i] == nums2[j]) return nums1[i];
            else if(nums1[i] < nums2[j]) i = i+1;
            else if(nums2[j] < nums1[i]) j = j+1;
        }
        return -1;
    }
};