class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        long long int n = nums.size();
        vector<long long int> pref(n), suf(n);
        pref[0] = nums[0]; suf[n-1] = nums[n-1];
        for(int i=1; i<n; i++)
        {
            pref[i] = nums[i]+pref[i-1];
            suf[n-1-i] = nums[n-1-i]+suf[n-i];
        }
        long long int valid = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                if(suf[i] == pref[i]) valid = valid + 2;
                else if(abs(suf[i]-pref[i]) == 1) valid = valid + 1;
            }
        }
        return valid;
    }
};