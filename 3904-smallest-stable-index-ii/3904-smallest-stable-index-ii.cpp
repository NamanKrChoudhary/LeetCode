class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        long long int n = nums.size();
        vector<int> premax(n,0), sufmin(n,0); premax[0] = nums[0];
        sufmin[n-1] = nums[n-1];
        for(int i=1; i<n; i++)
        {
            premax[i] = max(premax[i-1], nums[i]);
        }
        for(int i=n-2; i>=0; i--) sufmin[i] = min(sufmin[i+1], nums[i]);
        for(int i=0; i<n; i++)
        {
            if(premax[i]-sufmin[i] <= k) return i;
        }
        return -1;
    }
};