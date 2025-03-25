class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n), brr(n);
        for(int i=0; i<n; i++)
        {
            int temp = 0;
            int ways = 0;
            for(int j=0; j<i; j++)
            {
                if(nums[j] < nums[i]) temp = max(temp, arr[j]);
            }
            arr[i] = temp + 1;
            for(int j=0; j<i; j++)
            {
                if(nums[j] < nums[i] && arr[j] == temp) ways = ways+brr[j];
            }
            brr[i] = max(1,ways);
        }
        int ans = 0;
        int temp = 1;
        for(int i = 0; i<n; i++)
        {
            temp = max(temp, arr[i]);
        }
        for(int i=0; i<n; i++)
        {
            if(temp == arr[i]) ans = ans + brr[i];
        }
        return max(1,ans);
    }
};