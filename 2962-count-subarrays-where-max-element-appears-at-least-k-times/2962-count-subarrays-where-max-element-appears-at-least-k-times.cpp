class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int i = 0, j=0;
        long long int currk = 0;
        long long int count = 0;
        long long int maxx = *max_element(nums.begin(), nums.end());
        while(j<=nums.size() && i < nums.size())
        {
            while(currk < k && j< nums.size())
            {
                if(nums[j] == maxx) currk = currk + 1;
                j++;
            }
            if(currk >= k) count = count + (nums.size()-j)+1;
            if(nums[i] == maxx) currk = currk -1;
            i++;
        }
        return count;
    }
};