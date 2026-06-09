class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxx = 0, minn = 1e9+7;
        for(int i=0; i<nums.size(); i++)
        {
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
        }
        long long int min1 = minn, max1 = maxx;
        long long int req = (max1-min1)*k;
        return req;
    }
};