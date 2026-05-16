class Solution {
public:
    int findMin(vector<int>& nums) {
        long long int n = nums.size();
        if(n == 1) return nums[0];
        long long int st = 0, end = n-1;
        while(st <= end && nums[st] == nums[end]) st = st + 1;
        if(st >= end) return nums[0];
        if(nums[st] < nums[end]) return nums[st];
        long long int mid = st + ((end-st)/2);
        long long int minn = nums[end];
        long long int start = st;
        while(st <= end)
        {
            mid = st + ((end-st)/2);

            if(nums[mid] >= nums[start]) {st = mid+1;}
            else if(nums[mid] <= nums[n-1]) {minn = min(minn, static_cast<long long int>(nums[mid])); end = mid-1;}
        }
        return minn;
    }
};