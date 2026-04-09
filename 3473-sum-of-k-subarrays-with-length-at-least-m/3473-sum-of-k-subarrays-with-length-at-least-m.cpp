class Solution {
public:
    long long int filler(vector<long long int>& nums, vector<vector<vector<long long int>>>& dp, long long int curri, long long int rem, long long int stat, long long int m, vector<long long int>& pref)
    {
        if(curri < 0) return 0;
        //cout << curri << endl;
        if(dp[curri][rem][stat] != LLONG_MIN) return dp[curri][rem][stat];
        if(stat == 0)
        {
            if(rem == 0) return 0;
            long long int req1 = LLONG_MIN, req2 = pref[curri]-pref[curri-m+1]+nums[curri-m+1];
            //for(int i=0; i<m; i++) req2 = req2 + nums[curri-i];
            
            if(m*rem < curri+1) 
            {
                if(curri-1 >= 0) req1 = filler(nums, dp, curri-1, rem, stat, m, pref);
                //else if(curri-1>=0) req1 = dp[curri-1][rem][stat];
                if(curri-m >= 0) req2 = req2 + filler(nums, dp, curri-m, rem-1, 1, m, pref);
                //else if(curri-m >= 0) req2 = req2 + dp[curri-m][rem-1][1];
            }
            else
            {
                if(curri-m >= 0) req2 = req2 + filler(nums, dp, curri-m, rem-1, 0, m, pref);
                //else if(curri-m>=0) req2 = req2 + dp[curri-m][rem-1][0];
            }
            dp[curri][rem][stat] = max(req1, req2);
        }
        else
        {
            long long int req1 = LLONG_MIN, req2 = LLONG_MIN;
            if(m*rem < curri+1)
            {
                req1 = nums[curri];
                if(curri-1>=0) req1 = req1 + filler(nums, dp, curri-1, rem, stat, m, pref);
                //else if(curri-1 >= 0) req1 = req1 + dp[curri-1][rem][stat];
            }
            req2 = filler(nums, dp, curri, rem, 0, m, pref);
            //else req2 = dp[curri][rem][0];
            dp[curri][rem][stat] = max(req1, req2);
        }
        return dp[curri][rem][stat];
    }
    int maxSum(vector<int>& nums, int k, int m) {
        long long int n = nums.size();
        vector<vector<vector<long long int>>> dp(n, vector<vector<long long int>>(k+1, vector<long long int>(2,LLONG_MIN)));
        vector<long long int> num(n);
        for(int i=0; i<n; i++) num[i] = nums[i];
        vector<long long int> pref(n);
        pref[0] = nums[0];
        for(int i=1; i<n; i++) pref[i] = pref[i-1] + nums[i];
        return filler(num, dp, n-1,  k, 0, m, pref);
    }
};