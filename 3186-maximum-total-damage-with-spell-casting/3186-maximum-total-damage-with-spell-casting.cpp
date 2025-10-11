class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // state dp[i] = the maximum total damage possible till power = i;
        // transition = dp[i] = max(dp[i-3]+(i*freq[i]), dp[i-2], dp[i-1]);
        map<long long int, long long int> mp;
        for(int i=0; i<power.size(); i++)
        {
            mp[power[i]]++;
        }
        vector<pair<long long int, long long int>> freq;
        for(auto i: mp) freq.push_back(i);
        sort(freq.begin(), freq.end());
        vector<long long int> dp(freq.size());
        for(int i=0; i<freq.size(); i++)
        {
            long long int maxx = (freq[i].first*freq[i].second);
            if(i>0 && freq[i].first-freq[i-1].first > 2)
            {
                maxx = maxx + dp[i-1];
                dp[i] = maxx;
            }
            else if(i > 1 && freq[i].first-freq[i-2].first > 2)
            {
                maxx = maxx + dp[i-2];
                maxx = max(maxx, dp[i-1]);
                dp[i] = maxx;
            }
            else if(i>2)
            {
                maxx = maxx + dp[i-3];
                maxx = max(maxx, dp[i-1]);
                maxx = max(maxx, dp[i-2]);
                dp[i] = maxx;
            }
            else if(i>1)
            {
                maxx = max(maxx, dp[i-1]);
                maxx = max(maxx, dp[i-2]);
                dp[i] = maxx;
            }
            else if(i>0)
            {
                maxx = max(maxx, dp[i-1]);
                dp[i] = maxx;
            }
            else dp[i] = maxx;
        }
        return dp[dp.size()-1];
    }
};