class Solution {
public:
    long long int maxi(vector<int>& arr, vector<vector<long long int>>& dp, long long int curri, long long int currj, long long int currm)
    {
        if(curri >= arr.size()) return 0;
        if(dp[curri][currj] != -1e16) return dp[curri][currj];
        long long int next = -1e16;
        long long int stones = 0;
        long long int n = arr.size();
        for(long long int i=curri; i<=currj; i++)
        {
            stones = stones + arr[i];
            long long int nextm = max(currm, i-curri+1);
            long long int currstones = maxi(arr, dp, i+1, min(i+(2*nextm), n-1), nextm);
            currstones = stones - currstones;
            next = max(currstones, next);
        }
        return dp[curri][currj] = next;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<long long int>> dp(piles.size(), vector<long long int>(piles.size(), -1e16));
        if(piles.size() == 1) return piles[0];
        maxi(piles, dp, 0, 1, 1);
        // for(int i=0; i<piles.size(); i++)
        // {
        //     for(int j=0; j<piles.size(); j++) cout << dp[i][j] << " "; cout << endl;
        // }
        long long int total = 0;
        for(int i=0; i<piles.size(); i++) total = total + piles[i];
        long long int curr = (total + dp[0][1])/2;
        return curr;
    }
};