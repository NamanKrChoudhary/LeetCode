class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        long long int n = nums.size();
        sort(nums.begin(), nums.end());
        long long int prevBound = nums[0] - k;
        nums[0] = nums[0]-k;
        for(int i=1; i<n; i++)
        {
            if(nums[i]+k > prevBound) 
            {
                nums[i] = max(prevBound+1, static_cast<long long int>(nums[i]-k));
                prevBound = nums[i];
            } 
        }
        map<long long int, long long int> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        return mp.size();
    }
};