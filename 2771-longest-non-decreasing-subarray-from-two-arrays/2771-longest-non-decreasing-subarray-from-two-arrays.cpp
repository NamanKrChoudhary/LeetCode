class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        long long int n = nums1.size();
        vector<vector<long long int>> arr(n, vector<long long int>(2));
        arr[0][0] = 1; arr[0][1] = 1;
        for(int i=1; i<n; i++)
        {
            arr[i][0] = 1;
            if(nums1[i] >= nums1[i-1]) arr[i][0] = arr[i][0] + arr[i-1][0];
            if(nums1[i] >= nums2[i-1]) arr[i][0] = max(arr[i][0], 1+arr[i-1][1]);
            arr[i][1] = 1;
            if(nums2[i] >= nums1[i-1]) arr[i][1] = arr[i][1] + arr[i-1][0];
            if(nums2[i] >= nums2[i-1]) arr[i][1] = max(arr[i][1], 1 + arr[i-1][1]);
        }
        long long int req = 1;
        for(int i=0; i<n; i++)
        {
            req = max(req, arr[i][0]);
            req = max(req, arr[i][1]);
        }
        return req;
    }
};