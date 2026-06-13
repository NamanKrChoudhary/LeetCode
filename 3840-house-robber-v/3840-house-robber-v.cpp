class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<vector<long long int>> dp(nums.size(), vector<long long int>(2,0));
        dp[0][0] = 0; dp[0][1] = nums[0];
        for(long long int i=1; i<nums.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            if(colors[i] == colors[i-1])
            {
                dp[i][1] = nums[i] + dp[i-1][0];
            }
            else
            {
                dp[i][1] = nums[i] + max(dp[i-1][0], dp[i-1][1]);
            }
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};