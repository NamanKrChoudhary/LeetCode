class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        map<long long int, long long int> mp;
        multiset<pair<long long int, long long int>> ms;
        long long int n = nums.size();
        vector<long long int> req;
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i]) == mp.end()) 
            {
                mp[nums[i]] = freq[i];
                ms.insert({mp[nums[i]], nums[i]});
            }
            else
            {
                if(mp[nums[i]] > 0) ms.erase({mp[nums[i]], nums[i]});
                mp[nums[i]] = mp[nums[i]] + freq[i];
                if(mp[nums[i]] > 0) ms.insert({mp[nums[i]], nums[i]});
            }
            if(ms.empty()) {req.push_back(0); continue;}
            pair<long long int, long long int> curr = *ms.rbegin();
            req.push_back(curr.first);
        }
        return req;
    }
};