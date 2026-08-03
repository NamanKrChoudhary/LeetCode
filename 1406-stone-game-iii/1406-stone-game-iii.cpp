class Solution {
public:
    pair<long long int, long long int> filler(vector<vector<pair<long long int, long long int>>>& dp, vector<int>& nums, long long int curri, long long int currp)
    {
        if(curri >= nums.size()) return {0,0};
        if(!(dp[curri][currp].first == -1e13 && dp[curri][currp].second == -1e13)) return dp[curri][currp];
        pair<long long int, long long int> onesum = filler(dp, nums, curri+1, (currp+1)%2);
        if(currp == 0) onesum.first = onesum.first + nums[curri];
        else onesum.second = onesum.second + nums[curri];
        dp[curri][currp] = onesum;
        if(curri+1 < nums.size())
        {
            pair<long long int, long long int> twosum = filler(dp, nums, curri+2, (currp+1)%2);
            if(currp == 0)
            {
                twosum.first = twosum.first + nums[curri] + nums[curri+1];
                if(dp[curri][currp].first < twosum.first) dp[curri][currp] = twosum;
                else if(dp[curri][currp].first == twosum.first && dp[curri][currp].second > twosum.second) dp[curri][currp] = twosum;
            }
            else
            {
                twosum.second = twosum.second + nums[curri] + nums[curri+1];
                if(dp[curri][currp].second < twosum.second) dp[curri][currp] = twosum;
                else if(dp[curri][currp].second == twosum.second && dp[curri][currp].first > twosum.first) dp[curri][currp] = twosum;
            }
        }
        if(curri+2 < nums.size())
        {
            pair<long long int, long long int> threesum = filler(dp, nums, curri+3, (currp+1)%2);
            if(currp == 0)
            {
                threesum.first = threesum.first + nums[curri] + nums[curri+1] + nums[curri+2];
                if(dp[curri][currp].first < threesum.first) dp[curri][currp] = threesum;
                else if(dp[curri][currp].first == threesum.first && dp[curri][currp].second > threesum.second) dp[curri][currp] = threesum;
            }
            else
            {
                threesum.second = threesum.second + nums[curri] + nums[curri+1] + nums[curri+2];
                if(dp[curri][currp].second < threesum.second) dp[curri][currp] = threesum;
                else if(dp[curri][currp].second == threesum.second && dp[curri][currp].second > threesum.second) dp[curri][currp] = threesum;
            }
        }
        return dp[curri][currp];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        long long int n = stoneValue.size();
        vector<vector<pair<long long int, long long int>>> dp(n, vector<pair<long long int, long long int>>(2, {-1e13,-1e13}));
        pair<long long int, long long int> curr = filler(dp, stoneValue, 0, 0);
        // for(int i=0; i<n; i++) cout << dp[i][0].first << " " << dp[i][0].second << endl;
        // for(int i=0; i<n; i++) cout << dp[i][1].first << " " << dp[i][1].second << endl;
        if(curr.first > curr.second) return "Alice";
        else if(curr.first < curr.second) return "Bob";
        else return "Tie";
    }
};