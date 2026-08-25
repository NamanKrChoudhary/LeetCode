class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        long long int n = stones.size();
        long long int a = 0, b = 0;
        //multiset<long long int> ms;
        vector<long long int> pref(n); pref[0] = stones[0];
        //ms.insert(pref[0]);
        for(int i=1; i<n; i++)
        {
            pref[i] = pref[i-1] + stones[i];
            //ms.insert(pref[i]);
        }
        bool check = true;
        long long int i = 0;
        //for(int i=0; i<n; i++) cout << pref[i] << " "; cout << endl;
        vector<long long int> dp(n); dp[n-1] = pref[n-1];
        for(int i=n-2; i>0; i--)
        {
            dp[i] = max(pref[i]-dp[i+1], dp[i+1]);
        }
        return dp[1];
    }
};