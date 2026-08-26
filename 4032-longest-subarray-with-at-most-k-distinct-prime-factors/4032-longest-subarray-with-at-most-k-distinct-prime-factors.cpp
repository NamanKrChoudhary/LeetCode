class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        long long int n = nums.size();
        long long int maxx = nums[0];
        for(long long int i: nums) maxx = max(i, maxx);
        vector<long long int> spf(maxx+1,0);
        for(long long int i=2; i<=maxx; i++)
        {
            if(spf[i] == 0)
            {
                spf[i] = i;
                for(long long int j=i*i; j<=maxx; j=j+i)
                {
                    spf[j] = i;
                }
            }
        }
        map<long long int, long long int> mp;
        int req = 0;
        for(int i=0,j=0; i<n && j<n; j++)
        {
            long long int temp = nums[j];
            while(temp > 1)
            {
                mp[spf[temp]]++;
                long long int div = spf[temp];
                while(div == spf[temp]) temp = temp/spf[temp];
            }
            while(mp.size() > k && i<=j)
            {
                temp = nums[i];
                while(temp > 1)
                {
                    mp[spf[temp]]--;
                    if(mp[spf[temp]] == 0) mp.erase(spf[temp]);
                    long long int div = spf[temp];
                    while(div == spf[temp]) temp = temp/spf[temp];
                }
                i = i+1;
            }
            if(j>=i) req = max(req, j-i+1);
        }
        return req;
    }
};