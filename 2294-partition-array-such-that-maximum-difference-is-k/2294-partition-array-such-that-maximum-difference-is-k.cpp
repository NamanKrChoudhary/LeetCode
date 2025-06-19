class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        vector<long long int> arr(nums.size());
        for(int i=0; i<nums.size(); i++) arr[i] = nums[i];
        sort(arr.begin(), arr.end());
        long long int cnt = 1, minn = arr[0];
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]-minn > k) {cnt = cnt + 1; minn = arr[i];}
        }
        return cnt;
    }
};