class Solution {
public:
    const long long int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        long long int n = nums.size();
        map<long long int, long long int> mp1, mp2;
        vector<pair<long long int, long long int>> trip(nums.size(), {0,0});
        for(int i=0; i<n; i++)
        {
            if(mp1.find((nums[i]*2)) != mp1.end()) trip[i].first = mp1[nums[i]*2];
            mp1[nums[i]]++;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(mp2.find(nums[i]*2) != mp2.end()) trip[i].second = mp2[nums[i]*2];
            mp2[nums[i]]++;
        }
        long long int reqtrip = 0;
        for(int i=0; i<n; i++) reqtrip = (reqtrip + (trip[i].first*trip[i].second)%mod )%mod;
        return reqtrip;
    }
};