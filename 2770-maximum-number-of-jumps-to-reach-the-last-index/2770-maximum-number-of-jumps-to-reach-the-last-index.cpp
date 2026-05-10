class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        long long int n = nums.size();
        vector<long long int> reach(n, -1);
        reach[0] = 0;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(reach[j] != -1 && abs(nums[i]-nums[j]) <= (target))
                {
                    reach[i] = max(reach[i], reach[j]+1);
                }
            }
        }
        return reach[n-1];
    }
};