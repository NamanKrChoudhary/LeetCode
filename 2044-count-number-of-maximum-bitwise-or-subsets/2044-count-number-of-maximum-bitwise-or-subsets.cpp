class Solution {
public:

    void possible(vector<vector<int>>& dp, vector<int>& arr, long long int curr, long long int req, long long int mask, long long int curri)
    {
        if(curri == arr.size()) return;
        long long int now1 = curr|arr[curri];
        long long int mask1 = (mask*2)+1;
        long long int now2 = curr;
        long long int mask2 = (mask*2);
        cout << curri << " " << req << " " << now1 << " " << now2 << endl;
        if(dp[curri][mask1] == -1) possible(dp, arr, now1, req, mask1, curri+1);
        if(dp[curri][mask2] == -1) possible(dp, arr, now2, req, mask2, curri+1);
        if(now1 == req) dp[curri][mask1] = 1;
        if(now2 == req) dp[curri][mask2] = 1;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        long long int req = 0;
        for(int i=0; i<nums.size(); i++) req = req|nums[i];
        long long int p = 1;
        for(int i=0; i<nums.size(); i++) p = (p*2);
        vector<vector<int>> dp(nums.size(), vector<int>(p,-1));
        possible(dp, nums, 0, req, 0, 0);
        long long int ans = 0;
        long long int n = nums.size();
        for(int j=0; j<p; j++)
            {
                if(dp[n-1][j] != -1) ans = ans + dp[n-1][j];
            }
        return ans;
    }
};