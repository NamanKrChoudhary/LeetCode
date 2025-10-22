class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        long long int ops = numOperations;
        long long int n = nums.size(); 
        map<long long int, long long int> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        vector<long long int> val, freq;
        for(auto i: mp) 
        {
            val.push_back(i.first);
            freq.push_back(i.second);
        }
        for(int i=1; i<freq.size(); i++) freq[i] = freq[i] + freq[i-1];
        long long int maxx = 0;
        for(int i=0; i<freq.size(); i++)
        {
            long long int right = (upper_bound(val.begin(), val.end(), val[i]+(2*k)) - val.begin());
            if(upper_bound(val.begin(), val.end(), val[i]+(2*k)) == val.end()) right = n-freq[i]+mp[val[i]];
            else right = freq[right]-freq[i]+mp[val[i]] - mp[val[right]];
            if(mp.find(val[i]+k) != mp.end()) 
            {
                right = right - mp[val[i]+k];
                maxx = max(maxx, mp[val[i]+k]+min(ops, right));
            }
            else
            {
                maxx = max(maxx, min(right, ops));
            }
            

            long long int left = lower_bound(val.begin(), val.end(), val[i]-(2*k)) - val.begin();
            left = freq[i]-freq[left]+mp[val[left]];
            if(mp.find(val[i]-k) != mp.end()) 
            {
                left = left - mp[val[i]-k];
                maxx = max(maxx, mp[val[i]-k]+min(left, ops));
            }
            else
            {
                maxx = max(maxx, min(left, ops));
            }
            //cout << i << " " << maxx << endl;


            long long int mid = 0;
            if(upper_bound(val.begin(), val.end(), val[i]+k) == val.end()) 
            {
                long long int leftind = lower_bound(val.begin(), val.end(), val[i]-k)-val.begin();
                mid = n-freq[leftind] + mp[val[leftind]] - mp[val[i]];
            }
            else 
            {
                long long int leftind = lower_bound(val.begin(), val.end(), val[i]-k)-val.begin();
                long long int rightind = upper_bound(val.begin(), val.end(), val[i]+k)-val.begin();
                mid = freq[rightind] - freq[leftind] + mp[val[leftind]] - mp[val[rightind]] - mp[val[i]];
            }
            maxx = max(maxx, mp[val[i]] + min(mid, ops));
        }
        return maxx;
    }
};