class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        long long int n = nums.size();
        vector<long long int> prev(n,0), suf(n,0);
        prev[0] = 1;
        for(int i=1; i<n; i++) 
        {
            if(nums[i] >= nums[i-1]) prev[i] = 1+prev[i-1];
            else prev[i] = 1;
        }
        suf[n-1] = 1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] <= nums[i+1]) suf[i] = suf[i+1] + 1;
            else suf[i] = 1;
        }
        if(nums.size() < 3) return nums.size();
        long long int maxx = max(1+suf[1], 1+prev[n-2]);
        for(int i=1; i<n-1; i++)
        {
            if(nums[i-1] <= nums[i+1]) maxx = max(maxx, prev[i-1]+1+suf[i+1]);
            maxx = max(maxx, prev[i-1]+1);
            maxx = max(maxx, 1+suf[i+1]);
        }
        // for(int i=0; i<n; i++) cout << prev[i] << " "; cout << endl;
        // for(int i=0; i<n; i++) cout << suf[i] << " "; cout << endl;
        return maxx;
    }
};