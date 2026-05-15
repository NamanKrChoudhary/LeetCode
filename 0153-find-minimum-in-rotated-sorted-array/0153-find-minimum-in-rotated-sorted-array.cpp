class Solution {
public:
    int findMin(vector<int>& nums) {
        long long int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] < nums[n-1]) return nums[0];
        long long int minn = 1e9;
        long long int st = 0, end = n-1, mid = st + ((end-st)/2);
        while(st <= end)
        {
            mid = st + ((end-st)/2);
            if(nums[mid] >= nums[0]) {st = mid+1;}
            else if(nums[mid] <= nums[n-1]) {minn = min(minn, static_cast<long long int>(nums[mid])); end = mid-1;}
        }
        return minn;
    }
};