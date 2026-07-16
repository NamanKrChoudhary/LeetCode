class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long int n = nums.size();
        vector<long long int> pref(n,0);
        int maxx = 0;
        for(int i=0; i<n; i++)
        {
            maxx = max(nums[i], maxx);
            pref[i] = __gcd(nums[i], maxx);
        }
        sort(pref.begin(), pref.end());
        long long int sum = 0;
        long long int i = 0, j = n-1;
        while(i < j)
        {
            sum = sum + __gcd(pref[i], pref[j]);
            i = i+1; j = j-1;
        }
        return sum;
    }
};