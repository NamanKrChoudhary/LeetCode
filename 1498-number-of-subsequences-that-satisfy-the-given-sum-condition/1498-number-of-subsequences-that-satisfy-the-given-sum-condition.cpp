class Solution {
public:
    const long long int mod = 1e9+7;

    long long int modpow(long long int a, long long int b)
    {
        long long int res = 1;
        while(b)
        {
            if(b&1) res = (res*a)%mod;
            a = (a*a)%mod;
            b = b/2;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        vector<long long int> temp;
        for(int i=0; i<nums.size(); i++) temp.push_back(nums[i]);
        sort(temp.begin(), temp.end());
        long long int ways = 0;
        for(int i=0; i<temp.size(); i++)
        {
            if(temp[i] <= target)
            {
                long long int it = upper_bound(temp.begin(), temp.end(), target-temp[i]) - temp.begin();
                if(it > i) {long long int cpow = modpow(2, it-i-1); ways = (ways + cpow)%mod;}
            }
        }
        return ways;
    }
};