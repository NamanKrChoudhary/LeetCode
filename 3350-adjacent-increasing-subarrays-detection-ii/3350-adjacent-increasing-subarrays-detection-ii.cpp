class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        long long int n = nums.size();
        long long int st = 1, end = n/2, mid = st + ((end-st)/2);
        vector<long long int> pref(n), vis(n);
        for(int i=1; i<n; i++)
        {
            if(nums[i] > nums[i-1]) {pref[i] = pref[i] + pref[i-1]+1; vis[i] = 1;}
            else {pref[i] = pref[i-1]; vis[i] = 0;}
        }
        long long int reqk = 1;
        while(st <= end)
        {
            mid = st + ((end-st)/2);
            long long int i = 0, j=mid, k = (2*mid)-1;
            bool check = false;
            for(; i<n && j<n && k<n; i++, j++, k++)
            {
                long long int prevsum = pref[j-1]-pref[i];
                long long int postsum = pref[k]-pref[j];
                if(prevsum == mid-1 && postsum == mid-1){check = true; break;}
            }
            if(check)
            {
                reqk = max(reqk, mid);
                st = mid+1;
            }
            else end = mid-1;
        }
        return reqk;
    }
};