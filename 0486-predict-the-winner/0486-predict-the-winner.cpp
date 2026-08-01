class Solution {
public:
// dp[i][j][0] = max each guy can make if starting with player1 in interval i...j;
// dp[i][j][1] = max each guy can make if starting with player2 in interval i...j; given each playing optimally.
// dp[i][j][0].first = max(nums[i]+dp[i+1][j][1].first, nums[j]+dp[i][j-1][1].first);
    bool predictTheWinner(vector<int>& nums) {
        long long int n = nums.size();
        vector<vector<vector<pair<long long int,long long int>>>> dp(n, vector<vector<pair<long long int, long long int>>>(n, vector<pair<long long int, long long int>>(2,{0,0})));
        for(int i=0; i<n; i++) {dp[i][i][0] = {nums[i], 0}; dp[i][i][1] = {0, nums[i]};}
        for(int sz = 2; sz<=n; sz++)
        {
            for(int i=0, j=sz-1; i<n && j<n; i=i+1, j=j+1)
            {
                if(dp[i+1][j][1].first + nums[i] > dp[i][j-1][1].first + nums[j])
                {
                    dp[i][j][0].first = dp[i+1][j][1].first + nums[i];
                    dp[i][j][0].second = dp[i+1][j][1].second;
                }
                else 
                {
                    dp[i][j][0].first = dp[i][j-1][1].first + nums[j];
                    dp[i][j][0].second = dp[i][j-1][1].second;
                }
                if(dp[i+1][j][0].second + nums[i] > dp[i][j-1][0].second + nums[j])
                {
                    dp[i][j][1].second = dp[i+1][j][0].second + nums[i];
                    dp[i][j][1].first = dp[i+1][j][0].first;
                }
                else
                {
                    dp[i][j][1].second = dp[i][j-1][0].second + nums[j];
                    dp[i][j][1].first = dp[i][j-1][0].first;
                }
            }
        }
        if(dp[0][n-1][0].first >= dp[0][n-1][0].second) return true;
        return false;
    }
};