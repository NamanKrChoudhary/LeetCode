class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        long long int n = nums.size();
        map<long long int, long long int> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        long long int maxx = 1;
        int right = 0, left = 0;
        for(int i=0; i<=k; i++) if(mp.find(i) != mp.end()) right = right + mp[i];
        long long int maxel = *max_element(nums.begin(), nums.end());
        long long int minel = *min_element(nums.begin(), nums.end());
        for(int i=1; i<=maxel; i++)
        {
            if(mp.find(i+k) != mp.end()) right = right + mp[i+k];
            long long int curr = 0;
            if(mp.find(i) != mp.end())
            {
                right = right - mp[i];
                curr = curr + mp[i];
            }
            if(mp.find(i-1) != mp.end())
            {
                left = left + mp[i-1];
            }
            if(mp.find(i-k-1) != mp.end()) left = left - mp[i-k-1];
            curr = curr + min(numOperations, left+right);
            maxx = max(maxx, curr);
        }
        return maxx;
    }
};