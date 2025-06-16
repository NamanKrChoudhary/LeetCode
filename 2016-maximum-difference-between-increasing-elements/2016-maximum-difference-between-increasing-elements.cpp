class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        long long int maxi = -1;
        long long int maxx = -1;
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(maxi > nums[i]) maxx = max(maxx, maxi-nums[i]);
            maxi = max(int(maxi), nums[i]);
        }
        return maxx;
    }
};